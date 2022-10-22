#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
int du[N],p[N];bool bk[N];

int main()
{

    int T;scanf("%d",&T);
    while(T--){
        int n,st;
        scanf("%d%d",&n,&st);

        for(int i=1;i<=n;i++) du[i]=0;
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            du[x]++;du[y]++;
        }

        for(int i=1;i<=n;i++) scanf("%d",&p[i]);

        int id=-1;
        for(int i=1;i<=n;i++)
            if(du[i]==n-1) {id=i;break;}
        
        if(id==-1){
            printf("Alice\n");
            continue;
        }

        int Sum=0;
        for(int i=1;i<=n;i++) bk[i]=true;
        for(int i=1;i<=n;i++)
            if(bk[i]){
                int t=i;Sum++;
                while(bk[t]) bk[t]=false,t=p[t];
            }
        if(st==id){
            if(p[id]!=id) printf("Bob\n");
            else{
                if((n-Sum)%2==1||n-Sum==0) printf("Alice\n");
                else printf("Bob\n");
            }
        }
        else{
            if(p[id]!=id){
                if(st!=p[id]){
                    if(n-Sum<=2||(n-Sum)%2==0) printf("Alice\n");
                    else printf("Bob\n");
                }
                else printf("Bob\n");
            }
            else{
                bool pd=true;
                for(int i=1;i<=n;i++)
                    if(p[i]!=i&&st==i) {pd=false;break;}
                if((n-Sum)%2==0||(n-Sum==1&&pd)) printf("Alice\n");
                else printf("Bob\n");
            }
        }
    }

    return 0;
}