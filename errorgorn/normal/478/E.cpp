#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define fi first
#define se second

#define puf push_front
#define pof pop_front
#define pub push_back
#define pob pop_back
#define lb lower_bound
#define ub upper_bound

#define rep(x,s,e) for (int x=(s)-((s)>(e));x!=(e)-((s)>(e));((s)<(e))?x++:x--)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
int pre[14][10]; //[b][a], find a*10**b % n
int memo[14][10][2][100005]; //[pos][digit][asc/dsc][res]
//0: a>b
//1: a<b

int count(int i){
	if (i==0) return 0;
	
	int res=0;
	rep(x,1,min(9LL,i-1)+1) if (x%n==0) res--;
	
	vector<int> d={i};
	while (d.back()>=10){
		d.pub(d.back()/10);
		d[sz(d)-2]%=10;
	}
	reverse(all(d));
	//for (auto it:d) cout<<it<<" "; cout<<endl;
	
	rep(x,0,sz(d)-1) rep(digit,1,10){
		res+=memo[x][digit][0][0]+memo[x][digit][1][0];
	}
	
	int s=sz(d)-1;
	rep(digit,1,d[0]){
		res+=memo[s][digit][0][0]+memo[s][digit][1][0];
	}
	
	int curr=(n-pre[s][d[0]])%n;
	
	if (sz(d)>1){
		rep(digit,0,d[1]){
			if (d[0]<digit) res+=memo[s-1][digit][0][curr];
			if (d[0]>digit) res+=memo[s-1][digit][1][curr];
		}
		
		bool flag;
		if (d[0]<d[1]) flag=true;
		else if (d[0]>d[1]) flag=false;
		else return res;
		
		curr=(curr-pre[s-1][d[1]]+n)%n;
		
		rep(x,2,sz(d)){
			rep(digit,0,d[x]){
				if (flag && d[x-1]>digit){
					res+=memo[s-x][digit][1][curr];
				}
				if (!flag && d[x-1]<digit){
					res+=memo[s-x][digit][0][curr];
				}
			}
			
			if (flag){
				if (d[x-1]<=d[x]) return res;
			}
			else{
				if (d[x-1]>=d[x]) return res;
			}
			flag^=true;
			
			curr=(curr-pre[s-x][d[x]]+n)%n;
		}
	}
	
	return res+(curr==0);
}

bitset<20000005> good;
bitset<20000005> good2;
bitset<20000005> temp;

signed main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);
	
	rep(x,0,20) good[x]=1;
	rep(x,10,10000000){
		int a=(x/10)%10,b=x%10;
		if (a>b && good[x/10*2]) good[x*2+1]=1;
		if (a<b && good[x/10*2+1]) good[x*2]=1;
	}
	
	int Z=10;
	rep(x,0,2*Z) good2[x]=1;
	rep(x,0,6){
		Z*=10;
		rep(x,0,2*Z) temp[x]=0;
		rep(x,0,Z){
			int a=(x/10)%10,b=x%10;
			if (a>b && good2[x/10*2]) temp[x*2+1]=1;
			if (a<b && good2[x/10*2+1]) temp[x*2]=1;
		}
		rep(x,0,2*Z) good2[x]=temp[x];
	}
	
	cin>>n>>k;
	
	if (n>100000){
		k++;
		int res=0;
		for (int x=0;x<10000000;x++) if (good[x*2] || good[x*2+1]){
			//find shit in [x*10^7,(x+1)*10^7)
			int l=x*10000000,r=(x+1)*10000000-1;
			l=(l+n-1)/n;
			r=r/n;
			
			rep(y,l,r+1){
				int small=y*n%10000000;
				bool ok=false;
				if (x==0){
					if (good[small*2] || good[small*2+1]) ok=true;
				}
				else{
					int a=x%10,b=small/1000000;
					if (a>b && (good[x*2]) && (good2[small*2+1])) ok=true;
					if (a<b && (good[x*2+1]) && (good2[small*2])) ok=true;
				}
				
				if (ok){
					res++;
					if (res==k){
						cout<<y*n<<endl;
						return 0;
					}
				}
			}
		}
		
		cout<<"-1"<<endl;
	}
	else{
		rep(x,0,10) pre[0][x]=x%n;
		rep(y,1,14) rep(x,0,10) pre[y][x]=pre[y-1][x]*10%n;
		
		rep(x,0,10){
			memo[0][x][0][x%n]=memo[0][x][1][x%n]=1;
		}
		rep(x,1,14) rep(y,0,n){
			int curr=0;
			rep(digit,0,10){
				memo[x][digit][0][pre[x][digit]]+=curr;
				curr+=memo[x-1][digit][1][y];
			}
			
			curr=0;
			rep(digit,10,0){
				memo[x][digit][1][pre[x][digit]]+=curr;
				curr+=memo[x-1][digit][0][y];
			}
			
			rep(digit,0,10){
				pre[x][digit]++;
				if (pre[x][digit]==n) pre[x][digit]=0;
			}
		}
		
		int lo=0,hi=1e14,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			if (count(mi)<k) lo=mi;
			else hi=mi;
		}
		
		if (hi==1e14) cout<<"-1"<<endl;
		else cout<<hi<<endl;
	}
}