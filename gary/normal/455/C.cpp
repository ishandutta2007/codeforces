/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	
	
	 
	c[i]
	
	long long
	
	dp
	
	 >=0
	
	dpg
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
	
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define IT iterator
#define FIR first
#define SEC second
using namespace std;
const int MAX=0x3f3f3f3f;
const int MOD=1e9+7;
const int MAXN=300010;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,q,belong[MAXN],dsu[MAXN],farest,Y;int vis[MAXN];
struct node{
	vector<int> son;
}father[MAXN];
void dfs(int last,int now,int id,int de){
//	return;
//	if(vis[now]) return;
	vis[now]=1;
//	cout<<last<<" "<<now<<endl;
//	cout<<now<<endl;
//	toever[id][now]=de;
	if(de>=farest){
	farest=de;Y=now;
	} 
	int sz=father[now].son.size();
	rb(i,0,sz-1){
		if(father[now].son[i]==last) continue;
		dfs(now,father[now].son[i],id,de+1);
	}
}
int find(int A){
	if(belong[A]==A) return A;
	return belong[A]=find(belong[A]);
}
void merge(int A,int B){
	if(find(A)==find(B)) return;
	dsu[find(B)]=max(max(dsu[find(B)],dsu[find(A)]),int(ceil(double(dsu[find(A)])/2))+int(ceil(double(dsu[find(B)])/2))+1);
	belong[find(A)]=find(B);
}
int main(){
//	freopen("out.out","r",stdin);
	scanf("%d %d %d",&n,&m,&q);
	
	rb(i,1,n) belong[i]=i,dsu[i]=0;
	rb(i,1,m){
		int ai,bi;
		scanf("%d %d",&ai,&bi);
//		merge(ai,bi);
		if(find(ai)!=find(bi))
		belong[find(ai)]=find(bi);
		father[bi].son.push_back(ai);
		father[ai].son.push_back(bi);
	}
	rb(i,1,n){
//		cout<<"Try->"<<i<<endl;
		if(vis[i]) continue;
		vis[i]=1;
//		memset(toever,0,sizeof(toever));
		farest=-1;
		Y=find(i);
		dfs(-1,find(i),0,0);
		farest=-1;
		dfs(-1,Y,1,0);
//		cout<<i<<endl;
		dsu[find(i)]=farest;
	}
//	rb(i,1,n) cout<<dsu[find(i)]<<" ";
	rb(i,1,q){
		int t;
		scanf("%d",&t);
		if(t==1){
			int xi;
			scanf("%d",&xi);
			printf("%d\n",dsu[find(xi)]);
		}
		else{
			int xi,yi;
			scanf("%d %d",&xi,&yi);
			merge(xi,yi);
		}
	}
	return 0;
}