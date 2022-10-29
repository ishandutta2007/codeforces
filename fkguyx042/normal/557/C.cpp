#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
#include <algorithm>  
int N;  
struct node{  
    int l,d;  
}G[100005];  
int num[100005];  
int c[100005];  
int n[100005];  
int D[205];  
bool cmp(node a,node b){  
    if(a.l==b.l) return a.d<b.d;  
    return a.l<b.l;  
}  
  
  
int main(){  
    scanf("%d",&N);  
    for(int i=0;i<N;i++){  
        scanf("%d",&G[i].l);  
        num[G[i].l]++;  
    }  
    for(int i=0;i<N;i++){  
        scanf("%d",&G[i].d);  
    }  
    sort(G,G+N,cmp);  
    c[0]=G[0].d;  
    for(int i=1;i<N;i++){  
        c[i]=c[i-1]+G[i].d;  
    }  
    n[0]=0;  
    for(int i=1;i<=100000;i++){  
        n[i]=n[i-1]+num[i];  
    }  
    int res=100000000;  
    for(int i=1;i<=100000;i++){  
        if(!num[i]) continue;  
        int cur=c[N-1]-c[n[i]-1];  
        int tmp=n[i]-(num[i]*2-1);  
        while(tmp>0){  
            for(int i=1;i<=200;i++){  
                if(D[i]<=tmp){  
                    cur+=D[i]*i;  
                    tmp-=D[i];  
                }  
                else if(tmp<D[i]){  
                    cur+=tmp*i;  
                    tmp=0;  
                }  
            }  
        }  
        res=min(res,cur);  
        for(int j=n[i-1];j<n[i];j++){  
            D[G[j].d]++;  
        }  
    }  
    printf("%d\n",res);  
    return 0;  
}