#include <stdio.h>

using namespace std;

int n, m;
int a[1005][1005];
bool b[1005][1005];
int l[1005], lN;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i < n; ++i)
        for(int j=0; j < m; ++j){
            scanf("%d", a[i]+j);
        }
    int Min=-1, Max=1000000005;
    while(Max-Min > 1){
        int test=(Max+Min)/2;
        for(int i=0; i < m; ++i)
            for(int j=0; j < m; ++j)
                b[i][j]=0;
        bool rect=0;
        for(int i=0; i < n && !rect; ++i){
            lN=0;
            for(int j=0; j < m; ++j)
                if(a[i][j] >= test)
                    l[lN++]=j;
            for(int j=0; j < lN; ++j)
                for(int k=j+1; k < lN; ++k){
                    if(b[l[j]][l[k]])
                        rect=1;
                    b[l[j]][l[k]]=1;
                }
        }
        if(rect)
            Min=test;
        else Max=test;
    }
    printf("%d", Min);
    return 0;
}