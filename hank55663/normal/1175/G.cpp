#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))

struct node{
    node *l,*r;
    vector<pair<int,pii> > v;
    int a,b;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){
        v.clear();
    }
}*root;
void build(node *n,int *dp){
    vector<pair<int,pii> > &v=n->v;
    for(int i = n->a;i<=n->b;i++){
        while(!v.empty()){
            auto p=v.back();
            v.pop_back();
            p.x=(p.y.y-dp[i])/(-i-p.y.x);
            if(!v.empty()&&v.back().x>=p.x){
                continue;
            }
            v.pb(p);
            break;
        }
        v.pb(mp(1e9,mp(-i,dp[i])));
    }
    reverse(v.begin(),v.end());
    if(n->a==n->b){
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,dp);
    build(n->r,dp);
}
int query(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        while(n->v.back().x<k){
            n->v.pop_back();
        }
        return n->v.back().y.x*k+n->v.back().y.y;
    }
    if(n->b<l||n->a>r)return 1e9;
    return min(query(n->l,l,r,k),query(n->r,l,r,k));
}
int dp[105][20005];
struct Line{
    int x,a,b;
};
int op;
bool operator<(const Line &l1,const Line &l2){
    if(op){
        return l1.x<l2.x;
    }
    return l1.a>l2.a;
}
int inter(Line l1,Line l2){
    return (l2.b-l1.b)/(l1.a-l2.a);
}
void erase(node *n){
    if(!n)return ;
    erase(n->l);
    erase(n->r);
    delete n;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int A[20005];
    for(int i = 1;i<=n;i++)
        scanf("%d",&A[i]);
    int Max=0;
    for(int i = 1;i<=n;i++){
        Max=max(Max,A[i]);
        dp[1][i]=Max*i;
    }
    for(int i = 2;i<=k;i++){
        root = new node(1,n);
        build(root,dp[i-1]);
        vector<pii> stk;
        stk.pb(mp(1e9,i-1));
        vector<vector<pair<Line,int> > > s(20005);
        int now=-1;
        for(int j = i;j<=n;j++){
            while(stk.back().x<=A[j]){
                stk.pop_back();
            }
            int a=A[j],b=query(root,stk.back().y,j-1,A[j]);
            stk.pb(mp(A[j],j));
            op=0;
            while(now!=-1&&s[now].back().x.a<=A[j]){
                int temp = s[now].back().y;
                s[now].pop_back();
                if(temp!=now-1&&now!=0){
                    s[now-1].back().x.x = inter(s[now-1].back().x,s[now].back().x);
                }
                now=temp;
            }
            Line l;
            l.a=a;
            l.b=b;
            l.x=1e9;
            int last=now;
            while(now!=-1){
                Line ll = s[now].back().x;
                now--;
                ll.x=inter(ll,l);
                if(now!=-1&&s[now].back().x.x>=ll.x){
                    continue;
                }
                now++;
                s[now].back().x.x=ll.x;
                break;
            }
            now++;
            s[now].pb(mp(l,last));
            op=1;
            int Max=now,Min=-1;
            while(Max>Min+1){
                int mid=(Max+Min)/2;
                if(s[mid].back().x.x>=j){
                    Max=mid;
                }
                else{
                    Min=mid;
                }
            }
            Line res= s[Max].back().x;
            dp[i][j]=res.a*j+res.b;
        }
        erase(root);
    }
    printf("%d\n",dp[k][n]);
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/