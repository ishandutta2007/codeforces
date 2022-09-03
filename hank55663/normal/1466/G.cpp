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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
const int mod=1e9+7;
LL cnt[100005][26];
vector<char> v;
LL p2[100005];
int Next[1000005];
int from[1000005];
void erase(int x){
    from[Next[x]]=from[x];
    Next[from[x]]=Next[x];
}
void add(int x){
    from[Next[x]]=x;
    Next[from[x]]=x;
}
char t[100005];
LL dc(int x,int s,int k){
    if(s>k)return 0;
    if(x==1){
        char val=v[Next[0]-1];
        //printf("?%c %d %d\n",val,cnt[k][val-'a'],cnt[s-1][val-'a']);
        return ((cnt[k][val-'a']-cnt[s-1][val-'a']*p2[k-s+1])%mod+mod)%mod;
    }
    vector<int> arr;
    int now=0;
    int st=Next[0];
    char val=t[s];
    int ok=1;
    LL res=0;
    while(st<=v.size()){
        arr.pb(st);
        int tmp=st;
        if(val!=v[st-1]){
            ok=0;
            break;
        }
        st=Next[Next[st]];
        erase(tmp);
    }
    if(ok)res+=dc(x-arr.size(),s+1,k);
    while(arr.size()){
        add(arr.back());
        arr.pop_back();
    }
    st=Next[Next[0]];
    val=t[s];
    ok=1;
    while(st<=v.size()){
        arr.pb(st);
        int tmp=st;
        if(val!=v[st-1]){
            ok=0;
            break;
        }
        st=Next[Next[st]];
        erase(tmp);
    }
    if(ok)res+=dc(x-arr.size(),s+1,k);
    while(arr.size()){
        add(arr.back());
        arr.pop_back();
    }
    res%=mod;
    return res;
}
bool solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    char c[105];

    scanf("%s %s",c,t+1);
    //for(int i=1;i<=n;i++)t[i]='a';
    p2[0]=1;
    for(int i = 1;i<=n;i++)p2[i]=p2[i-1]*2%mod;
    for(int i = 1;i<=n;i++){
        for(int j =0;j<26;j++)cnt[i][j]=cnt[i-1][j]*2%mod;
        cnt[i][t[i]-'a']++;
        //printf("%d %d\n",i,cnt[i]['b'-'a']);
    }
    v.reserve(1000005);
    Next[0]=1;
    for(int i = 1;i<=1000002;i++){
        Next[i]=i+1;
        from[i]=i-1;
    }
    while(q--){
        int k;
        char qc[1000005];
        scanf("%d %s",&k,qc);
        LL ans=0;
        for(int i = 0;i==0||c[i-1]!=0;i++){
            int now=i;
            int ok=1;
            v.clear();
            for(int j = 0;qc[j]!=0;j++){
                if(c[now]==0){
                    v.pb(qc[j]);
                    now=0;
                    continue;
                }
                if(c[now]!=qc[j]){
                    ok=0;
                    break;
                }
                now++;
            }
            if(!ok)continue;
           // for(auto it:v)printf("%c ",it);
            //printf("\n");
            if(v.empty())ans+=p2[k];
            else{
                ans+=dc(v.size(),1,k);
            }
            ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return true;
}
int main(){
    int t=1;00000;
   // scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/