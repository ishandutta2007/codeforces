#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 100005
struct node{
	node *n[2];
	int value;
	node(){//(NULL),r(NULL){
		n[0]=n[1]=NULL;
		value=1e9;
	}
};
int Value(node* n){
	return n?n->value:1e9;
}
void pull(node *n){
	n->value=min(Value(n->n[0]),Value(n->n[1]));
}
void add(node *n,int k){
	bitset<17> b(k);
	vector<node*> stk;
	for(int i =16;i>=0;i--){
		if(!n->n[b[i]]){
			n->n[b[i]]=new node();
		}
		stk.pb(n);
		n=n->n[b[i]];
	}
	n->value=k;
	while(stk.size()){
		pull(stk.back());
		stk.pop_back();
	}
}
int query(node *n,int x,int s){
	node *now =n;
	int ret=-1;
	//printf("%d\n",Value(n));
	if(Value(n)+x>s)return -1;
	for(int i = 16;i>=0;i--){
		int value=(1<<i)&x;
		if(value){
			if(Value(n->n[0])+x<=s){
				n=n->n[0];
			}
			else{
				n=n->n[1];
			}
		}
		else{
			if(Value(n->n[1])+x<=s){
				n=n->n[1];
			}
			else{
				n=n->n[0];
			}
		}
	}
	return n->value;
}
vector<int> factor[100005];
node* root[100005];
int main(){
	for(int i =1;i<100005;i++){
		for(int j=i;j<100005;j+=i){
			factor[j].pb(i);
		}
	}
	for(int i = 1;i<=100000;i++)
	root[i]=new node();
	int q;
	scanf("%d",&q);
	while(q--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int u;
			scanf("%d",&u);
			for(auto it:factor[u]){
				add(root[it],u);
			//	printf("%d\n",it);
			}
		}
		else{
			int x,k,s;
			scanf("%d %d %d",&x,&k,&s);
			if(x%k!=0){
				printf("-1\n");
			}
			else
			printf("%d\n",query(root[k],x,s));
		}
	}
}