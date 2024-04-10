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
LL S[300005];
void add(int x,int k){
    for(int i = x;i<300005;i+=i&-i){
        S[i]+=k;
    }
}
LL query(int x){
    LL res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
int ans[300005];
int val[600005];
mt19937 Rnd(114514);
int mrand(){
    return Rnd()%1000000000;
}
void solve(int T){
    int n,q;
    scanf("%d %d",&n,&q);
    int a[300005],ori[300005];
    map<int,int> m;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
       // a[i]=mrand();
        ori[i]=a[i];
        m[a[i]];
    }
    vector<vector<int> > v;
    for(int i = 0;i<q;i++){
        int op=2;
        scanf("%d",&op);
        if(op==1){
            int i,x;
            scanf("%d %d",&i,&x);
            v.pb({op,i,x});
            m[x];
        }
        else{
            int l,r,k;
         //   l=rand()%n+1;
         //   r=rand()%n+1;
         //   if(l>r)swap(l,r);
           // k=2;
            scanf("%d %d %d",&l,&r,&k);
            v.pb({op,l,r,k});
            ans[i]=1;
            if((r-l+1)%k!=0)ans[i]=0;
        }
    }
    int index=0;
    for(auto &it:m)it.y=++index;
    for(int i = 1;i<=n;i++){
        ori[i]=m[ori[i]];
       // if(ori[i]>index)assert(0);
    }
    for(auto &it:v){
        if(it[0]==1)it[2]=m[it[2]];
    }
    for(int _=0;_<30;_++){
        MEM(S);
        for(int j = 1;j<=index;j++)val[j]=mrand();
        for(int i=1;i<=n;i++){
            a[i]=val[ori[i]];
            add(i,a[i]);
        }
        for(int i = 0;i<q;i++){
            if(v[i][0]==1){
                int vv=val[v[i][2]];
                add(v[i][1],vv-a[v[i][1]]);
                a[v[i][1]]=vv;
            }
            else if(ans[i]){
                LL x=query(v[i][2])-query(v[i][1]-1);
                if(x%v[i][3])ans[i]=0;
            }
        }
    }
    for(int i = 0;i<q;i++){
        if(v[i][0]==2){
            if(ans[i])printf("YES\n");
            else printf("NO\n");
        }
    }
}

int main(){
    srand(time(NULL));
    int t=1;
   //  scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
1
2 4
3 
5
*/