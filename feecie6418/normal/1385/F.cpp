#include<bits/stdc++.h>
using namespace std;
int n,k,d[200005],s[200005],h[200005],cnt;
struct E{
	int to,next;
}e[400005];
void Clear(){
	for(int i=1;i<=cnt;i++)e[i].to=e[i].next=0;
	cnt=0;
	for(int i=1;i<=n;i++){
		s[i]=d[i]=h[i]=0;
	}
}
void A(int x,int f){
	e[++cnt]={f,h[x]};
	h[x]=cnt;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++){
			scanf("%d%d",&x,&y);
			A(x,y),A(y,x),d[x]++,d[y]++;
		}
		if(n==2){
			cout<<1<<endl;
			Clear();
			continue;
		}
		int ss=n,ans=0;
		for(int i=1;i<=n;i++)if(d[i]==1)s[e[h[i]].to]++;
		while(1){
		queue<int> q;
		for(int i=1;i<=n;i++)if(s[i]>=k)q.push(i);
		if(!q.size())break;
		while(!q.empty()){
			int i=q.front();
			q.pop();
			if(s[i]<k||ss<=k)break;
			int p=s[i]/k*k;
			s[i]-=p,d[i]-=p,ss-=p,ans+=p/k;
			for(int j=h[i],lst=0;j;j=e[j].next){
				int y=e[j].to;
				if(d[y]==1){
					d[y]=h[y]=0;
					if(lst)e[lst].next=e[j].next;
					else h[i]=e[j].next;
				}
				else lst=j;
			}
			if(d[i]!=1)continue;
			s[e[h[i]].to]++;
			if(s[e[h[i]].to]>=k)q.push(e[h[i]].to);
		}}
		cout<<ans<<endl;
		Clear();
	}
	return 0;
}