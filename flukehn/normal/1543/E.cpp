#include<bits/stdc++.h>
using namespace std;
const int N=65636;
int e[N][20],d[N];
int n;
int p[N],q[N];
int vis[N],cnt=3;
void myassert(bool tmp){
	if(!tmp) {
		for(int i=0;;++i){
			e[abs(i)%N][2]=rand();
		}
	}
}
void work(vector<int> a){
//	cerr<<"size(a)="<<a.size()<<endl;
	if(a.size()==1){
		p[a[0]]=0;
		return;
	}
	cnt+=3;
	for(int x:a)vis[x]=cnt;
	int x=a[rand()%a.size()],y;
	vis[x]++;
	for(int i=0;i<n;++i)
		if(vis[y=e[x][i]]/3==cnt/3)
			break;
	vis[y]+=2;
	queue<int> q;
	q.push(x);
	q.push(y);
	vector<int> b;
	vector<int> c;
	while(!q.empty()){
		int w=q.front();
		q.pop();
		if(vis[w]%3==1)b.push_back(w);
		else c.push_back(w);
		for(int i=0;i<n;++i){
			int z;
			if(vis[z=e[w][i]]/3!=cnt/3)continue;
			if(vis[z]%3)continue;
			vis[z]=vis[w];
			q.push(z);
		}
	}
	int tmp=cnt;
	//cerr<<b.size()<<" "<<c.size()<<" "<<a.size()<<endl;
	myassert(b.size()==c.size());
	myassert(b.size()*2==a.size());
	//cerr<<b.size()<<" "<<c.size()<<" "<<a.size()<<endl;
	work(b);
	for(int x:b){
		for(int i=0;i<n;++i){
			int y;
			if(vis[y=e[x][i]]==tmp+2)
				p[y]=p[x]+b.size();
		}
	}
}
int ans[N];
int chk(int n){
	while(n>1){
		if(n%2)return 0;
		n/=2;
	}
	return 1;
}
int main(){
#ifdef flukehn
	freopen("e.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<(1<<n);++i)d[i]=0;
		for(int i=0;i<(1<<n);++i)p[i]=-1;
		for(int i=0;i<(1<<(n-1))*n;++i){
			int u,v;
			cin>>u>>v;
			e[u][d[u]++]=v;
			e[v][d[v]++]=u;
		}
		vector<int> a;
		for(int i=0;i<(1<<n);++i)
			a.push_back(i);
		work(a);
		//	cerr<<"ok"<<endl;
		for(int i=0;i<(1<<n);++i)myassert(p[i]>=0);
			//	cerr<<"ok1"<<endl;
		for(int i=0;i<(1<<n);++i)q[p[i]]=i;
		for(int i=0;i<(1<<n);++i)cout<<q[i]<<" \n"[i+1==(1<<n)];
			//	cerr<<"ok2"<<endl;
		if(!chk(n)){
			cout<<-1<<"\n";
		}else{
			if(n==1)cout<<"0 0\n";
			else{
				//myassert(n==2);
				ans[q[0]]=0;
				ans[q[2]]=1;
				ans[q[1]]=0;
				ans[q[3]]=1;
				for(int i=0;i<(1<<n);++i){
					int x=p[i],r=0;
					for(int j=0;j<n;++j)
						if(x>>j&1)r^=j;
					ans[i]=r;
				}
				for(int i=0;i<(1<<n);++i)
					cout<<ans[i]<<" \n"[i+1==(1<<n)];
			}
		}
	}
}