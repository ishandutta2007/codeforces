/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int res[2048+1];
int store[2049][2049];
bool vis[2049][2049];
int cnt=0;
int query(int x,int y){
	if(x>y) swap(x,y);
	if(vis[x][y]){
		return store[x][y];
	}
	cnt++;
	vis[x][y]=1;
	cout<<"? "<<x<<" "<<y<<endl;
	int res;
	ff;
	cin>>res;
	return store[x][y]=res; 
}
int a[200][200];
int bit_count(int number){
	int res=0;
	while(number){
		res+=(number)&1;
		number>>=1; 
	}
	return res;
}
int main(){
	fastio;
	SRAND;
	int n;
	cin>>n;
	if(n*(n-1)<=4269*2){
		rb(i,1,n)
			rb(j,i+1,n)
			
			{
				a[i][j]=a[j][i]=query(i,j);
			}
		int app[100]={0};
		rb(i,1,n){
			bool ok=1;
			memset(app,0,sizeof(app));
			rb(j,1,n){
				if(j==i) continue; 
				if(!app[a[i][j]]&&a[i][j]<n){
					app[a[i][j]]=1;
				}
				else{
					ok=0;
				}
			}
			if(ok)
			{
				cout<<"! ";
				rb(j,1,n){
					if(j==i){
						cout<<0<<" ";
					}
					else{
						cout<<a[i][j]<<" ";
					}
				}
				return 0;
			 } 
		}
	}
	vector<int> v;
	rb(i,1,n) v.PB(i);
    unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
    std::shuffle (v.begin (), v.end (), std::default_random_engine (seed));
	while(v.size()>2){
		int index=random(v.size());
		swap(v[0],v[index]);
		vector<mp> tmp;
		int Tmp=v[0];
		if(v.size()>=5){
			int pre=1<<11;
			pre-=1;
			rb(i,1,4){
				pre&=query(v[0],v[i]);
			}
			if(bit_count(pre)>6)
			{
				continue;
			}
		}
		rb(i,1,v.size()-1){
			tmp.PB(II(query(v[0],v[i]),v[i]));
		}
		sort(ALL(tmp));
		v.clear();
		v.PB(Tmp);
		v.PB(tmp[0].SEC);
		rb(i,1,tmp.size()-1){
			if(tmp[i].FIR!=tmp[i-1].FIR){
				break;
			}
			v.PB(tmp[i].SEC);
		}
	}
	int index=v[0];
	if(v.size()>1){
	int el=query(v[0],v[1]);
	bool ok=1;
	rb(i,1,10){
		int TT=random(n)+1;
		if(cnt+n==4269  )  break;
		if(TT!=v[0])
		if((el&query(TT,v[0]))!=el){
			ok=0;
			break;
		}
	}	
	if(ok) swap(v[0],v[1]);
	} 
	index=v[0];
	rb(i,1,n){
		if(i==index){
			continue;
		}
		res[i]=query(i,index);
	}
	cout<<"! ";
	rb(i,1,n){
		cout<<res[i]<<" ";
	}
	return 0;
}