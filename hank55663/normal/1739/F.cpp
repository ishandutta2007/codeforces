
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
int cnt[22][22];
struct Node{
	Node *index[30];
	Node *fail;
    int dp[1<<12];
    int vis[1<<12];
    Node *from[1<<12];
    char fromc[1<<12];
	int sc,pre;
	Node(){
        MEM(dp);
		for(int i=0;i<30;i++)
		index[i]=NULL;
		fail=NULL;
		sc=0;
	}
}*root=new Node();
void add(const char *c,int sc){
	Node *n=root;
	for(int i=0;c[i]!=0;i++){
		
		if(!n->index[c[i]-'a'])
		n->index[c[i]-'a']=new Node();
		n=n->index[c[i]-'a'];
	}
	n->sc+=sc;
}
void ac(){
	queue<Node*> q;
	q.push(root);
	root->fail=NULL;
	while(!q.empty()){
		Node *n=q.front();
		q.pop();
		for(int i=0;i<30;i++){
			if(n->index[i]){
				q.push(n->index[i]);
				Node* p=n->fail;
				while(p!=NULL&&!p->index[i])
				p=p->fail;
				if(p){
				    n->index[i]->fail=p->index[i];
                    n->index[i]->sc+=p->index[i]->sc;
                }
                else
				n->index[i]->fail=root;
			}
		}
	} 
}
Node *res;
int val;
void dfs(Node *n){
    if(!n)return;
    if(n->dp[(1<<12)-1]>val){
        res=n;
        val=n->dp[(1<<12)-1];
    }
    for(int i = 0;i<12;i++)dfs(n->index[i]);
}
void solve(int T){
    int n;
    scanf("%d",&n);
    vector<pair<string,int> > v;
    for(int i = 0;i<n;i++){
        int c;
        char s[2005];
        scanf("%d %s",&c,s);
        MEM(cnt);
        for(int j=0;s[j+1]!=0;j++){
            cnt[s[j]-'a'][s[j+1]-'a']=cnt[s[j+1]-'a'][s[j]-'a']=1;
        }
        int Max=0;
        for(int j =0;j<12;j++){
            int tot=0;
            for(int k =0;k<12;k++){
                if(cnt[j][k])tot++;
            }
            Max=max(Max,tot);
        }
        if(Max<=2){
            for(int j=0;j<12;j++){
                 int tot=0;
                for(int k =0;k<12;k++){
                    if(cnt[j][k])tot++;
                }
                if(tot==1){
                    string tmp;
                    tmp+=(char)(j+'a');
                    int now=j,last=-1;
                    while(true){
                        int ok=0;
                        for(int k = 0;k<12;k++){
                            if(cnt[now][k]&&k!=last){
                                last=now;
                                now=k;
                                  tmp+=(char)(now+'a');
                                ok=1;
                            }
                        }
                        if(!ok)break;
                    }
                    add(tmp.c_str(),c);
                 //   printf("%s %d\n",tmp.c_str(),c);
                }
            }
        }
    }
    ac();
    queue<pair<Node*,int> > q1,q2;
    q1.push(mp(root,0));
    while(!q1.empty()){
        while(!q1.empty()){
            auto p=q1.front();
           // printf("%d\n",p.y);
            q1.pop();
            for(int j = 0;j<12;j++){
                if((1<<j)&p.y);
                else{
                    Node *n=p.x;
                    while(!n->index[j]&&n!=root){
                        n=n->fail;
                    }
                    if(n->index[j])n=n->index[j];
                    int tar=p.y+(1<<j);
                    if(!n->vis[tar]){
                        n->vis[tar]=1;
                        q2.push(mp(n,tar));
                    }
                    if(n->dp[tar]<=p.x->dp[p.y]+n->sc){
                        n->dp[tar]=p.x->dp[p.y]+n->sc;
                        n->fromc[tar]=j+'a';
                        n->from[tar]=p.x;
                    }
                }
            }
        }
        swap(q1,q2);
    }
    res=root;
    val=root->dp[(1<<12)-1];
    vector<char> cc;
    int now=(1<<12)-1;
    dfs(root);
    //printf("%d\n",val);
    while(now){
        cc.pb(res->fromc[now]);
        res=res->from[now];
     //   printf("%d %d\n",now,cc.back());
        assert(now&(1<<(cc.back()-'a')));
        now-=1<<(cc.back()-'a');
    }
    reverse(cc.begin(),cc.end());
    for(auto it:cc)printf("%c",it);
    printf("\n");
}
int main(){
    int t=1;
 //   scanf("%d",&t);
    for(int T=1;T<=t;T++){
       // cerr<<T<<endl;
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/