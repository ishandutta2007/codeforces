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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;

vector<int> v[500005];
void solve(){
    vector<string> s;
    //s.clear();
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        char c[1000005];
        scanf("%s",c);
        s.pb(string(c));
    }    
    int ans=0;
    //flow.init(2*n*m+2,0,2*n*m+1);
    for(int t=0;t<2;t++){
        //vector<> v;
        for(int i = 0;i<n;i++){
          //  deque<int> q;
            for(int j = (i&1)^t;j<m;j+=2){
                if(s[i][j]=='1'){
                    v[i].push_back(j);
                }
            }
          //  v.pb(q);
        }
        for(int i = 0;i<n;i++)reverse(v[i].begin(),v[i].end());
        while(true){
            vector<pii> tmp;
            for(int j = 0;j<n;j++){
                if(v[j].size()){
                    tmp.pb(mp(v[j].back(),j)),v[j].pop_back();
                }
            }
            sort(tmp.begin(),tmp.end());
            map<int,int> m;
            for(auto it:tmp){
                int ok=0;
                if(m.empty())m[it.y]=it.x,ok=1;//printf("%d %d\n",it.x,it.y);
                else{
                    auto it2=m.lower_bound(it.y);
                    if(it2==m.end()||abs(it2->x-it.y)>=abs(it2->y-it.x)){
                        if(it2==m.begin()){
                            m[it.y]=it.x;
                            ok=1;
                         //   printf("%d %d\n",it.x,it.y);
                        } else {
                            it2--;
                            if(abs(it.y-it2->x)>=abs(it.x-it2->y)){
                                m[it.y]=it.x;
                              //  printf("%d %d\n",it.x,it.y);
                                ok=1;
                            }
                        }
                    }
                }
                if(!ok){
                    v[it.y].pb(it.x);
                }
            }
            if(tmp.empty())break;
            ans++;
            //printf("%d\n",ans);
        }
    }
    printf("%d\n",ans);
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/