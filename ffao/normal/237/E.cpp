#include <stdio.h>
#include <deque>
#include <string.h>

using namespace std;

const int INF = 1e9;
int c[140][140],f[140][140],g[140][140];
int dist[140];
deque<int> q;
int n;
int prev[140];

char str[200];

int k;
int ansFlow;
int ansCost;

void flow(int s, int t){
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) f[i][j]=0;
    ansFlow=0;
    while(true){
        for (int i=0; i<n; i++){
            dist[i]=INF;
            prev[i]=-2;
        }
        prev[s]=-1;
        dist[s]=0;
        q.push_back(s);
        while (!q.empty()){
            int x = q.front();
            q.pop_front();
            for (int i=0; i<n; i++){ if (c[x][i]>f[x][i] &&
                dist[x]+g[x][i]<dist[i]){
                    dist[i]=dist[x]+g[x][i];
                    prev[i] = x;
                    q.push_back(i); 
                }
            }
        }
        int p = t;
        while (prev[p]>=0) p=prev[p];   
        if (prev[p]==-2){
            ansCost=0;
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++) ansCost+=f[i][j]*g[i][j];
            }
            break;
        }
        else {
            int menor = INF;
            p = t;
            while (prev[p]>=0){
                int q = prev[p];
                menor=min(menor,c[q][p]-f[q][p]);
                p=prev[p];
            }
            p = t;
            while (prev[p]>=0){
                int q = prev[p];
                f[q][p]+=menor;
                f[p][q]-=menor;
                p=prev[p];
            }
            ansFlow+=menor;
        }
    }
}

int main(){
    scanf("%s %d", str, &k);
    int tot = strlen(str);
    for (int i = 0; i < tot; i++) {
        c[k+str[i]-'a'][k+26+1]++;
    }
    
    for (int i = 0; i < k; i++) {
        int lim;
        scanf("%s %d", str, &lim);
        c[k+26][i] = lim;
        g[k+26][i] = i+1;
        g[i][k+26] = -i-1;
        
        int tam = strlen(str);
        for (int j = 0; j < tam; j++) {
            c[i][k+str[j]-'a']++;
            //printf("%d %d %d\n", i, k+str[i]-'a',c[i][k+str[i]-'a']); 
        }
        
    }
    
    n = k+26+2;
    flow(k+26, k+26+1);/*
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) if (c[i][j]!=0) printf("(%d,%d): c%d\n",i,j,c[i][j]);
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) if (c[i][j]!=0) printf("(%d,%d): f%d\n",i,j,f[i][j]);
    }*/
    if (ansFlow != tot) printf("-1\n");
    else printf("%d\n", ansCost/2);
    return 0;
}