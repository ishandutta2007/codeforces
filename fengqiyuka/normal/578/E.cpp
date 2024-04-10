#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+100;
char s[N];
struct tree{
	int l,r,lc,rc,c[2];
}tr[2*N];int len;
void build(int l,int r){
	int now=++len;
	tr[now].l=l;tr[now].r=r;
	tr[now].lc=tr[now].rc=-1;
	tr[now].c[0]=tr[now].c[1]=0;
	if(l<r){
		int mid=(l+r)>>1;
		tr[now].lc=len+1;build(l,mid);
		tr[now].rc=len+1;build(mid+1,r);
	}
}
void change(int now,int k,int ty,int c){
	if(tr[now].l==tr[now].r)
		{tr[now].c[ty]+=c;return ;}
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(k<=mid) change(lc,k,ty,c);
	else change(rc,k,ty,c);
	tr[now].c[0]=tr[lc].c[0]+tr[rc].c[0];
	tr[now].c[1]=tr[lc].c[1]+tr[rc].c[1];
}
int findans(int now,int l,int r,int ty){
	if(l>r) return -1;
	if(tr[now].l==tr[now].r){
		if(tr[now].c[ty]) return l;
		else return -1;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(l==tr[now].l&&r==tr[now].r){
		if(!tr[now].c[ty]) return -1;
		if(tr[lc].c[ty]) return findans(lc,l,mid,ty);
		else return findans(rc,mid+1,r,ty);
	}
	if(r<=mid) return findans(lc,l,r,ty);
	else if(mid<l) return findans(rc,l,r,ty);
	else{
		int t=findans(lc,l,mid,ty);
		if(t==-1) t=findans(rc,mid+1,r,ty);
		return t;
	}
}
int Ans[N];
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	build(1,len);
	int Sum=0;
	for(int i=1;i<=len;i++){
		if(s[i]=='L') change(1,i,0,1),Sum++;
		else change(1,i,1,1),Sum--;
	}
	int t=0,now=0,ans=0;
	//if(Sum==1) t=findans(1,1,len,0);
	//else t=findans(1,1,len,1),now=1;
	//Ans[++Ans[0]]=t;
	if(Sum==1) now=1;
	if(Sum==0) now=(s[1]=='L'?1:0);
	if(Sum==-1) now=0;
	for(int i=1;i<=len;i++){
		if(i>1) change(1,t,s[t]=='L'?0:1,-1);
		int t2=findans(1,t+1,len,1-now);
		if(t2!=-1){
			if(findans(1,t2+1,len,now)==-1&&findans(1,1,findans(1,1,len,1-now),now)==-1){
				int T=t;
				t=findans(1,1,len,1-now);
				if(T>t) ans++;
			}
			else t=t2;
		}
		else ans++,t=findans(1,1,len,1-now);
		Ans[++Ans[0]]=t;now=1-now;
	}
	printf("%d\n",ans);
	for(int i=1;i<=len;i++){
		printf("%d",Ans[i]);
		if(i<len) printf(" ");
		else printf("\n");
	}
	return 0;
}