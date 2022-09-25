#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n;
int pow[70];
vector<int> al[100100];
int w[100100];
int color[100100];
queue<int> q;
const int vertices=100010;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    unsigned long long k;
    for (int x=0;x<n;x++){
        scanf("%llu",&k);
        for (int y=0;y<64;y++){
            if (k&((unsigned long long)1<<y)){
                pow[y]++;
                al[x].push_back(vertices+y);
                al[vertices+y].push_back(x);
            }
        }
    }
    /// if same bit have cycle
    for (int x=0;x<70;x++){
        if (pow[x]>=3) {
            printf("3\n");
            return 0;
        }
    }
    ///else we run an instance of shortest cycle
    int ans=1000000000; ///stores shortest cycle
    int v;
    int c;
    for (int x=0;x<64;x++){
        ///root=x for this
        memset(w,-1,sizeof(w));
        memset(color,0,sizeof(color));
        c=1;
        w[vertices+x]=0;
        color[vertices+x]=0;
        for (vector<int>::iterator it=al[vertices+x].begin();it!=al[vertices+x].end();it++){
            w[*it]=1;
            color[*it]=c++;
            q.push(*it);
        }
        while (!q.empty()){
            v=q.front();
            q.pop();
            //printf("%d\n",v);
            for (vector<int>::iterator it=al[v].begin();it!=al[v].end();it++){
                if (w[(*it)]==-1){
                    w[(*it)]=w[v]+1;
                    color[(*it)]=color[v];
                    q.push(*it);
                }
                else if (color[*it]!=color[v] && color[*it]!=0 && w[*it]+w[v]>3){
                    ans=min(ans,w[*it]+w[v]);
                }
            }
        }
    }
    if (ans==1000000000) printf("-1\n");
    else printf("%d\n",(ans+1)>>1);
}