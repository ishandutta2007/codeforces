#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v;
vector<vector<int> > xprime;
struct Node{
	Node *index[10];
	Node *fail;
	int num;
    int word;
	Node(){
		for(int i=0;i<10;i++)
		index[i]=NULL;
		fail=NULL;
		num=0;
        word=0;
	}
}*root;//=new Node();
Node node[10005];
int t=0;
void add(vector<int> v){
	Node *n=root;
	for(int i=0;i<v.size();i++){
		if(!n->index[v[i]])
		n->index[v[i]]=&node[t++];
		n=n->index[v[i]];
	}
    n->word=1;
}
void ac(){
	queue<Node*> q;
	q.push(root);
	root->fail=NULL;
	while(!q.empty()){
		Node *n=q.front();
		q.pop();
		for(int i=0;i<10;i++){
			if(n->index[i]){
				q.push(n->index[i]);
				Node* p=n->fail;
				while(p!=NULL&&!p->index[i])
				p=p->fail;
				if(p)
				n->index[i]->fail=p->index[i];
				else
				n->index[i]->fail=root;
			}
		}
	} 
}
void dfs(int x,int tot){
    if(x==0){
        int ok=1;
        for(int i = 0;i<v.size();i++){
            int sum=0;
            for(int j = i;j<v.size();j++){
                sum+=v[j];
                if(tot%sum==0&&sum!=tot){
                    ok=0;
                }
            }
        }
        if(ok){
            xprime.pb(v);
            add(v);
           /* for(auto it:v)printf("%d",it);
            printf("\n");*/
        }
    }
    for(int i = 1;i<=9&&i<=x;i++){
        v.pb(i);
        dfs(x-i,tot);
        v.pop_back();
    }
}
int dp[2][10005];
void solve(){
    char c[1005];
    scanf("%s",c);
    int x;
    scanf("%d",&x);

    for(int i = 0;i<10000;i++){
        node[i].num=i;
    }
    root = &node[t++];
   
    dfs(x,x);
     ac();
    for(int j=0;j<10005;j++){
        dp[0][j]=-1;
    }
    dp[0][0]=0;
    int ans=0;
   // printf("%d\n",node[7].num);
    for(int i = 0;c[i]!=0;i++){
        for(int j =0;j<t;j++){
            dp[1][j]=dp[0][j];
        }
        for(int j = 0;j<t;j++){
            if(dp[0][j]!=-1){
                Node *n=&node[j];
                while(n!=root){
                   //  printf("%d %d %d\n",n,n->fail,root);
                    if(n->index[c[i]-'0'])break;
                   
                    n=n->fail;
                }
                if(n->index[c[i]-'0'])n=n->index[c[i]-'0'];
               // printf("%d %d %d",n->word,c[i]-'0',n->num);
                if(!n->word){
                    dp[1][n->num]=max(dp[1][n->num],dp[0][j]+1);
                }
            }
        }
      //  printf("\n");
        for(int j = 0;j<t;j++){
          //  printf("%d ",dp[1][j]);
            dp[0][j]=dp[1][j];
            ans=max(ans,dp[0][j]);
        }
    //    printf("\n");
    }
    printf("%d\n",strlen(c)-ans);
    
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/