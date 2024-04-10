#include <stdio.h>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

complex<int> A[100005], B[20005];
vector<complex<int> > Up, Down;
vector<int> UpX, DownX;

int main()
{
    int AN, BN;
    scanf("%d", &AN);
    for(int i=0; i < AN; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        A[i]=complex<int>(x, y);
    }
    int minA=0;
    for(int i=0; i < AN; ++i){
        if(real(A[i]) < real(A[minA]) || (real(A[i]) == real(A[minA]) && imag(A[i]) < imag(A[minA])))
            minA=i;
    }
    int up=(minA+1)%AN, down=(minA+AN-1)%AN;
    Up.push_back(A[minA]);
    Down.push_back(A[minA]);
    Up.push_back(A[up]);
    Down.push_back(A[down]);
    while(up != down){
        if(real(A[up]) < real(A[down])){
            up=(up+1)%AN;
            Up.push_back(A[up]);
        }
        else{
            down=(down+AN-1)%AN;
            Down.push_back(A[down]);
        }
    }
    for(int i=0; i < Up.size(); ++i)
        UpX.push_back(real(Up[i]));
    for(int i=0; i < Down.size(); ++i)
        DownX.push_back(real(Down[i]));
    scanf("%d", &BN);
    bool ok=1;
    for(int i=0; i < BN; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        B[i]=complex<int>(x, y);
        int u, d;
        u=lower_bound(UpX.begin(), UpX.end(), x)-UpX.begin();
        d=lower_bound(DownX.begin(), DownX.end(), x)-DownX.begin();
        if(u == 0 || d == 0){
            ok=0;
            break;
        }
        if(u >= UpX.size()){
            ok=0;
            break;
        }
        if(x == UpX[UpX.size()-1]){
            ok=0;
            break;
        }
        if(UpX[u] == x && DownX[d] == x && imag(Up[u]) > y && imag(Down[d]) < y)
            continue;
        complex<int> v[4];
        v[0]=Up[u-1];
        v[1]=Up[u];
        v[2]=Down[d];
        v[3]=Down[d-1];
        for(int j=0; j < 4; ++j){
            complex<int> v1=v[(j+1)%4]-v[j], v2=B[i]-v[j];
            if((real(v1) != 0 || imag(v1) != 0) && (long long(real(v2))*long long(imag(v1))-long long(real(v1))*long long(imag(v2)) <= 0)){
                ok=0;
                break;
            }
        }
    }
    printf(ok?"YES":"NO");
    return 0;
}