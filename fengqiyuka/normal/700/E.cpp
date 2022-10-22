#include<cstdio>
#include<cstring>
using namespace std;
const int N=4e5+100;
char s[N];
struct SAM{
	int son[26],link,len;
}tr[2*N];int sum=1;
struct tree{
	int lc,rc,c;
}Tr[60*N];int len=0,root[N],n;
struct edge{
	int x,y,next;
}a[2*N];int Len,last[N];
int mymax(int x,int y) {return x>y?x:y;}
void ins(int x,int y){
	a[++Len].x=x;a[Len].y=y;
	a[Len].next=last[x];last[x]=Len;
}
void merge(int &now1,int &now2){
	int t=now1;
	Tr[len+1]=Tr[now1];
	now1=++len;
	if(!now2) return ;
	if(!t) {Tr[now1]=Tr[now2];return ;}
	merge(Tr[now1].lc,Tr[now2].lc);
	merge(Tr[now1].rc,Tr[now2].rc);
	Tr[now1].c+=Tr[now2].c;
}
void change(int &now,int L,int R,int k){
	if(!now) now=++len;
	if(L==R) {Tr[now].c++;return ;}
	int mid=(L+R)>>1;
	int &lc=Tr[now].lc,&rc=Tr[now].rc;
	if(k<=mid) change(lc,L,mid,k);
	else change(rc,mid+1,R,k);
	Tr[now].c=Tr[lc].c+Tr[rc].c;
}
int findmin(int now,int L,int R){
	if(L==R) return L;
	int mid=(L+R)>>1;
	int lc=Tr[now].lc,rc=Tr[now].rc;
	if(Tr[lc].c) return findmin(lc,L,mid);
	else return findmin(rc,mid+1,R);
}
bool findans(int now,int L,int R,int l,int r){
	if(!now) return false;
	if(L==l&&R==r) return (Tr[now].c>0);
	int mid=(L+R)>>1;
	int lc=Tr[now].lc,rc=Tr[now].rc;
	if(r<=mid) return findans(lc,L,mid,l,r);
	else if(mid<l) return findans(rc,mid+1,R,l,r);
	else return (findans(lc,L,mid,l,mid)||findans(rc,mid+1,R,mid+1,r));
}
void dfs(int x){
	if(x==8){
		x++;x--;
	}
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		dfs(y);
		merge(root[x],root[y]);
	}
}
int d[N],ID=1,Min[N],f[N];
void dfs2(int x){
	int t=ID;
	if(x==8){
		x++;x--;
	}
	Min[x]=findmin(root[x],1,2*n);
	while(ID<=d[0]&&findans(root[d[ID]],1,2*n,Min[x]-tr[x].len+tr[d[ID]].len,Min[x]-1)) ID++;
	if(ID>1) f[x]=f[d[ID-1]]+1;
	else if(x>1) f[x]=1;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		d[++d[0]]=y;dfs2(y);d[0]--;
	}
	ID=t;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int now=1;
	for(int i=1;i<=n;i++){
		int t=s[i]-'a',las=now;
		now=++sum;tr[now].len=tr[las].len+1;
		if(i==6){
			i++;i--;
		}
		while(las&&!tr[las].son[t]) tr[las].son[t]=now,las=tr[las].link;
		if(las){
			int y=tr[las].son[t];
			if(tr[las].len+1==tr[y].len) tr[now].link=y;
			else{
				int z=++sum;
				tr[z]=tr[y];tr[z].len=tr[las].len+1;
				tr[y].link=tr[now].link=z;
				while(las&&tr[las].son[t]==y) tr[las].son[t]=z,las=tr[las].link;
			}
		}
		else tr[now].link=1;
		if(i==7){
			i++;i--;
		}
		change(root[now],1,2*n,i);
	}
	Len=0;memset(last,0,sizeof(last));
	for(int i=2;i<=sum;i++) ins(tr[i].link,i);
	dfs(1);
	dfs2(1);
	int ans=0;
	for(int i=1;i<=sum;i++){
		if(f[i]==6){
			i++;i--;
		}
		ans=mymax(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}