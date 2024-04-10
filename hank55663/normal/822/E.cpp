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
#define N 200005
#define rank Rank
int ss[N];
int heigh[N];
int sa[N];
int rank[N];
int length;
int val[30];
int c[N];   // counting sort array
int temp[2][N];
void suffix_array()
{
    int A = 30;          
    int* rank = temp[0];
    int* new_rank = temp[1];
    for (int i=0; i<A; ++i) c[i] = 0;
    for (int i=0; i<length; ++i) c[rank[i] = ss[i]]++;
    for (int i=1; i<A; ++i) c[i] += c[i-1];
    for (int i=length-1; i>=0; --i) sa[--c[ss[i]]] = i;
    for (int n=1; n<length; n*=2)
    {
        for (int i=0; i<A; ++i) c[i] = 0;
        for (int i=0; i<length; ++i) c[rank[i]]++;
        for (int i=1; i<A; ++i) c[i] += c[i-1];
        int* sa2 = new_rank;       
        int r = 0;                  
        for (int i=length-n; i<length; ++i)   
            sa2[r++] = i;           
        for (int i=0; i<length; ++i)    
            if (sa[i] >= n)       
                sa2[r++] = sa[i] - n;
        for (int i=length-1; i>=0; --i)
            sa[--c[rank[sa2[i]]]] = sa2[i];
        new_rank[sa[0]] = r = 0;
        for (int i=1; i<length; ++i)
        {
            if (!(rank[sa[i-1]] == rank[sa[i]] &&
                sa[i-1]+n < length &&    // stable sort trick
                rank[sa[i-1]+n] == rank[sa[i]+n]))
                r++;
            new_rank[sa[i]] = r;
        }
        swap(rank, new_rank);
        if (r == length-1) break;
        A = r + 1;
    }
}
void lcp_array()
{
    for (int i=0; i<length; ++i)
        rank[sa[i]] = i;
 
    for (int i=0, lcp=0,h=0; i<length; i++)
        if (rank[i] == 0)
            heigh[0] = 0;
        else
        {
            int j = sa[rank[i]-1];
            if (lcp > 0) lcp--,h--;
            while (ss[i+h] == ss[j+h]) lcp++,h++;
            heigh[rank[i]] = lcp;
        }
}
struct node{
    node *l,*r;
    int a,b;
    int Min;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Min(0){

    }
}*root;
void pull(node *n){
    n->Min=min(n->l->Min,n->r->Min);
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->Min=a[n->a];
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
int query(node *n,int l,int r){
    if(l>r)swap(l,r);
    if(n->a>l&&n->b<=r){
        return n->Min;
    }
    if(n->b<=l||n->a>r)return 1e9;
    return min(query(n->l,l,r),query(n->r,l,r));
}
int dp[100005][35];
int main(){
    int n,m,x;
    char s[100005],t[100005];
    scanf("%d %s %d %s %d",&n,s+1,&m,t+1,&x);
    for(int i = 1;i<=n;i++){
        ss[length++]=s[i]-'a';
    }
    ss[length++]=26;
    for(int i = 1;i<=m;i++){
        ss[length++]=t[i]-'a';
    }
    ss[length]=30;
    suffix_array();
   // printf("?\n");
    lcp_array();
    //printf("?\n");
    for(int i=0;i<length;i++){
        rank[sa[i]]=i;
    //    printf("%d ",heigh[i]);
    }
    root=new node(0,length-1);
    build(root,heigh);
   // printf("?\n");
    //printf("\n");
    for(int i = 1;i<=n;i++){
      //  printf("%d\n",i);
        for(int j=0;j<x;j++){
           // printf("%d %d\n",i,j);
            int now=dp[i-1][j]+1;
           // printf("!\n");
            int xx=query(root,rank[i-1],rank[now+n]);
            //printf("%d %d %d\n",i,now,xx);
           // printf("%d ?\n",xx);
            if(xx!=0){
                dp[i+xx-1][j+1]=max(dp[i+xx-1][j+1],now+xx-1);
                //printf("%d %d %d\n",i+xx-1,j+1,dp[i+xx-1][j+1]);
            }
        }
        for(int j = 0;j<=x;j++){
         //   printf("%d %d\n",i,j);
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
           // printf("%d %d %d?\n",i,j,dp[i][j]);
            if(dp[i][j]==m){
                printf("YES\n");
                return 0;
            }
        }
    }
    for(int j=0;j<=x;j++){
        if(dp[n+1][j]==m){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/