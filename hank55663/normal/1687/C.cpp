#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int ok[200005];
pii p[200005];
int cnt[200005];
vector<int> v[200005];
void solve(){
    set<int> s;
    int n,m;
    scanf("%d %d",&n,&m);
    fill(ok,ok+n+1,0);
    for(int i = 0;i<=n;i++){
        v[i].clear();
    }
    int a[200005],b[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    LL sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&b[i]);
        a[i]-=b[i];
        sum+=a[i];
    }
    if(sum){
        printf("NO\n");
        for(int i = 0;i<m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
        }
    }
    else{
        LL sum=0;
        ok[0]=1;
        for(int i = 0;i<n;i++){
            sum+=a[i];
            if(sum==0){
                ok[i+1]=1;

            }
            else{
                ok[i+1]=0;
                s.insert(i+1);
            }
        }
        queue<int> q;
        for(int i = 0;i<m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            x--;
            p[i]=mp(x,y);
            cnt[i]=0;
            if(ok[x]){cnt[i]++;
            }
            else{v[x].pb(i);}
            if(ok[y]){
                cnt[i]++;
            }
            else{
                v[y].pb(i);
            }
            if(cnt[i]==2)q.push(i);
        }
        while(!q.empty()){
            auto a=p[q.front()];
           // printf("%d\n",q.front());
            q.pop();
            auto it=s.lower_bound(a.x);
            while(it!=s.end()){
                if(*it>a.y)break;
                else{
                    auto it2=next(it);
                    for(auto x:v[*it]){
                        cnt[x]++;
                        if(cnt[x]==2)q.push(x);
                    }
                    s.erase(it);
                    it=it2;
                }
            }
        }
        if(s.size()){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
} 

int main(){
   
    int t=1;
   scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
0 1 2 3 4 5 6 7 
0 1 6 7 4 5 2 3
0 3 2 5 4 7 6 1
0 3 6 1 4 7 2 5
0 5 2 7 4 1 6 3
0 5 6 3 4 1 2 7
0 7 2 1 4 3 6 5
0 7 6 5 4 3 2 1
    a=p*1+(1-p)*(1+t2+a)
    a=p+q+q*t2+q*a
    a=(p+q+q*t2)/(1-q)
*/
/*
0 0 0 0
1 2 1 4
1 0 1 0
3 3 3 3
3 1 2 2
4 1 2 1
2 0 2 0

1 4 2 7 5 6 3
*/