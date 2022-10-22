#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

void umn(int &x,int y){x=min(x,y);}

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int n;
#define Maxn 1000010
struct Node{
	int son[26],fail;
	int len;
}tree[Maxn];
bool id[Maxn];
char *str[Maxn];int L[Maxn];
char ch[Maxn];

int root,cnt=0;
void Insert(int &k,int at,int up){
	if(!k){
		k=++cnt;
		tree[k].len=at-1;
	}
	if(at==up+1){
		id[k]=true;                      
		return;                                            
	}                                           
	Insert(tree[k].son[ch[at]-'a'],at+1,up);                  
}

int Q[Maxn],hd,tl;                                  
void Build_AC(){                      
	Q[tl++]=root;                                           
	while(hd<tl){                                      
		int k=Q[hd];hd++;                            
		int to;                                             
		for(int i=0;i<26;++i){                                      
			if(k==root)to=root;                                        
			else to=tree[tree[k].fail].son[i];                           
			if(tree[k].son[i]){                                      
				Q[tl++]=tree[k].son[i];                                 
				tree[tree[k].son[i]].fail=to;                      
			}else tree[k].son[i]=to;                        
		}                                                       
	}                                                   
}

int head[Maxn],v[Maxn],nxt[Maxn],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
}

int b[Maxn],out[Maxn],dfn[Maxn],dfk=0;
void dfs(int u){
	dfn[u]=++dfk;
	for(int i=head[u];i;i=nxt[i]){
		b[v[i]]=b[u];
		if(id[v[i]])b[v[i]]=v[i];
		dfs(v[i]);
	}
	out[u]=dfk;
}

int c[Maxn];
int tag[Maxn];

int mx[Maxn<<2];
void cl(int k,int l,int r,int p){
	mx[k]=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(p<=mid)cl(k<<1,l,mid,p);
	else cl(k<<1|1,mid+1,r,p);
}
void Modify(int k,int l,int r,int p,int t){
	if(l==r){
		mx[k]=max(mx[k],t);
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)Modify(k<<1,l,mid,p,t);
	else Modify(k<<1|1,mid+1,r,p,t);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
int query(int k,int l,int r,int L,int R){
	if(l==L&&r==R)return mx[k];
	int mid=(l+r)>>1;
	if(R<=mid)return query(k<<1,l,mid,L,R);
	else if(mid<L)return query(k<<1|1,mid+1,r,L,R);
	else return max(query(k<<1,l,mid,L,mid),query(k<<1|1,mid+1,r,mid+1,R));
}

int main(){
	rd(n);
	rep(i,1,n){
		scanf("%s",ch+1);
		int t=strlen(ch+1);
		L[i]=t;
		str[i]=new char[t+1];L[i]=t;
		rep(j,1,t)str[i][j]=ch[j];
		Insert(root,1,t);
	}
	Build_AC();
	rep(i,2,cnt)add_edge(tree[i].fail,i);
	dfs(1);
	int Ans=0;
	rep(i,1,n){
		int k=root,t=L[i];
		rep(j,1,t)c[j]=t+1;
		rep(j,1,t){
			k=tree[k].son[str[i][j]-'a'];
			if(j==t)k=tree[k].fail;
			int L=j-tree[b[k]].len+1;                        
			umn(c[j-1],L);                             
			umn(c[j],L+1);                      
		}
		per(j,t-1,1)umn(c[j],c[j+1]);                             
		k=root;                           
		rep(j,1,t){                                             
			k=tree[k].son[str[i][j]-'a'];                   
			if(j==t)k=tree[k].fail;                   
			Modify(1,1,cnt,dfn[k],j-c[j]+1);                 
		}
		k=root;int ans=0;                
		rep(j,1,t){                             
			k=tree[k].son[str[i][j]-'a'];                  
			if(j==t)k=tree[k].fail;               
			int y=b[k];             
			if(y>1&&tag[y]!=i){                    
				tag[y]=i;             
				if(query(1,1,cnt,dfn[y],out[y])<tree[y].len)ans++;
			}	
		}                                      
		k=root;
		rep(j,1,t){
			k=tree[k].son[str[i][j]-'a'];              
			if(j==t)k=tree[k].fail;                            
			cl(1,1,cnt,dfn[k]);                      
		}                          
		Ans+=ans;            
	}                          
	printf("%d\n",Ans);                                
	return 0;
}