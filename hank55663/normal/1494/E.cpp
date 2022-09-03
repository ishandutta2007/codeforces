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
map<string,int> m[200005];
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    int one=0,two=0;
    map<pii,char> edge;
    for(int i = 0;i<q;i++){
        char c;
        scanf(" %c",&c);
        if(c=='+'){
            int x,y;
            char c;
            scanf("%d %d %c",&x,&y,&c);
            if(edge.find(mp(y,x))!=edge.end()){
                string s;
                s+=c;
                s+=edge[mp(y,x)];
                two++;
                /*two+=m[y][s];
                m[y][s]++;
                swap(s[0],s[1]);
                two+=m[x][s];
                m[x][s]++;*/
                if(s[0]==s[1])one++;
            }
            edge[mp(x,y)]=c;
        }
        else if(c=='-'){
            int x,y;
            scanf("%d %d",&x,&y);
            char c=edge[mp(x,y)];
            if(edge.find(mp(y,x))!=edge.end()){
                string s;
                s+=c;
                s+=edge[mp(y,x)];
                /*m[y][s]--;
                two-=m[y][s];
                swap(s[0],s[1]);
                m[x][s]--;
                two-=m[x][s];*/
                two--;
                if(s[0]==s[1])one--;
            }
            edge.erase(mp(x,y));
        }
        else{
            int k;
            scanf("%d",&k);
            if(one)printf("YES\n");
            else if(two&&k%2==1)printf("YES\n");
            else printf("NO\n");
        }
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/