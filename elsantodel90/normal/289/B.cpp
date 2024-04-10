#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)(n); i++)

int obtenerMovidas(vector<vector<int> > & matriz, int m, int d){
    int total = 0;
    forn(i, matriz.size()){
        forn(j, matriz[i].size()){
            total+=abs(matriz[i][j]-m)/d;
        }
    }
    return total;
}

int main(){
    int n, m, d;
    cin>>n>>m>>d;
    vector< vector<int> > matriz(n, vector<int>(m));
    int restoD;
    bool esPosible=true;
    int minimo=10002, maximo=0;
    forn(i, n){
        forn(j, m){
            cin>>matriz[i][j];
            if(i==0 and j==0){
                restoD=matriz[i][j]%d;
            }else{
                if(restoD!=matriz[i][j]%d){
                    esPosible=false;
                }
            }
            matriz[i][j]-=(matriz[i][j]%d);
            minimo=min(minimo, matriz[i][j]);
            maximo=max(maximo, matriz[i][j]);
        }
    }
    if(esPosible){
        // El minimo seguro esta en el rango [a,b) elegido
        int a=minimo/d, b=maximo/d + 1;
        #define costo(x) obtenerMovidas(matriz, (x)*d, d)
        while (b-a>1)
        {
            int m1 = a + (b-a)/3;
            int m2 = a + (2*(b-a))/3;
            if (costo(m1) <= costo(m2))
                b = m2;
            else
                a = m1+1;
        }
        // El optimo se encuentra en a, pues el rango es [a,a+1)
        cout << costo(a) << endl;
    }else{
        cout << -1 << endl;
    }
}