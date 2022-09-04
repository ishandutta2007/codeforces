#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 2005
#define pi 3.14159265359
using namespace std;
struct name{
	string s1;
	string s2;
	string nick;
	int i;
}; 
bool operator<(const name &a,const name &b){
	if(a.s1!=b.s1)
	return a.s1<b.s1;
	return a.s2<b.s2;
}
bool cmp(const name&a,const name &b){
	return a.i<b.i;
}
int visit[4000];
vector<int> v[2005];
bool dfs(int n,int start){
	visit[n]=1;
	if(n/2==start/2&&n!=start)
	return false;
	int ok=true;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(!visit[*it])
		ok=ok&dfs(*it,start);
	}
	return ok;
}
name t[N];
void build(int n){
	visit[n]=1;
	if(n%2==0)
	t[n/2].nick=t[n/2].s1;
	if(n%2==1)
	t[n/2].nick=t[n/2].s2;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(!visit[*it])
		build(*it);
	}
}
int main()
{	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>t[i].s1;
		t[i].s1=t[i].s1.substr(0,3);
		cin>>t[i].s2;
		t[i].s2=t[i].s1.substr(0,2)+t[i].s2.substr(0,1);
		t[i].i=i; 
	}
	if(n==1){
		printf("YES\n");
		cout<<t[0].s1<<endl;
		return 0;
	}
	sort(t,t+n);
	set<string> s;
	map<string,vector<int> > m;
	int ok=1;
	if(t[0].s1==t[1].s1){
		t[0].nick=t[0].s2;
		s.insert(t[0].nick);
	//	cout<<t[0].nick;
	}
	else{
		m[t[0].s1].pb(0);
		m[t[0].s2].pb(1);
	}
	for(int i=1;i<n-1;i++){
		if(t[i].s1==t[i-1].s1){
			t[i].nick=t[i].s2;
			if(s.find(t[i].nick)!=s.end())
			ok=0;
		//	cout<<t[i].nick;
			s.insert(t[i].nick);
		}
		else if(t[i].s1==t[i+1].s1){
			t[i].nick=t[i].s2;
			if(s.find(t[i].nick)!=s.end())
			ok=0;
		//	cout<<t[i].nick;
			s.insert(t[i].nick);
		}
		else{
			m[t[i].s1].pb(2*i);
			m[t[i].s2].pb(2*i+1);
		}
	}
	if(t[n-1].s1==t[n-2].s1){
		t[n-1].nick=t[n-1].s2;
		if(s.find(t[n-1].nick)!=s.end())
		ok=0;
		//cout<<t[n-1].nick;
		s.insert(t[n-1].nick);
	}
	else{
		m[t[n-1].s1].pb(2*n-2);
		m[t[n-1].s2].pb(2*n-1);
	}
	if(!ok)
	printf("NO\n");
	else{
	//	printf("1");
		for(map<string,vector<int> >::iterator it=m.begin();it!=m.end();it++){
			if(s.find(it->x)!=s.end())
			for(vector<int>::iterator it2=it->y.begin();it2!=it->y.end();it2++){
				v[*it2].pb((*it2/2)*2+1-*it2%2);	
			} 
			else
			for(vector<int>::iterator it2=it->y.begin();it2!=it->y.end();it2++){
				for(vector<int>::iterator it3=it->y.begin();it3!=it->y.end();it3++){
					if(it2!=it3)
						v[*it2].pb((*it3/2)*2+1-*it3%2);
				}
			}
		}
		for(int i=0;i<n;i++){
			if(t[i].nick==""){
				memset(visit,0,sizeof(visit));
				bool a=dfs(i*2,i*2);
				memset(visit,0,sizeof(visit));
				bool b=dfs(i*2+1,i*2+1);
				if(!a&&!b){
					printf("NO\n");
					return 0;
				}
			} 
		}
		for(int i=0;i<n;i++){
			if(t[i].nick==""){
				memset(visit,0,sizeof(visit));
				bool a=dfs(i*2,i*2);
				memset(visit,0,sizeof(visit));
				bool b=dfs(i*2+1,i*2+1);
				if(!a&&b){
					build(i*2+1);
				}
				else if(a&&!b){
					build(i*2);
				}
			}
		}
		for(int i=0;i<n;i++){
			if(t[i].nick==""){
				memset(visit,0,sizeof(visit));
				build(i*2);
			}
		}
		sort(t,t+n,cmp);
		printf("YES\n");
		for(int i=0;i<n;i++)
		cout<<t[i].nick<<endl; 
	} 
}