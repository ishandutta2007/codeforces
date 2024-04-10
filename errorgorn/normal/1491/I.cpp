//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct dat{
	int a,b,c;
	int idx;
};

int n;
dat head;
deque<dat> dq;

dat state[6005];
dat trans_belt[6005];
bool green[6005];

int curr;
ll moves=1;

void brute(){
	rep(x,0,1000000){
		if ((curr==0?head.a:(curr==1?head.b:head.c))>dq.front().a){
			dq.pub(dq.front());
			dq.pof();
			curr++;
			if (curr==3){
				cout<<head.idx<<" "<<moves<<endl;
				exit(0);
			}
		}
		else{
			dq.pub(head);
			head=dq.front();
			dq.pof();
			curr=1;
		}
		
		moves++;
		
		if (x>n && curr==1) break;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	rep(x,0,n){
		int a,b,c;
		cin>>a>>b>>c;
		
		if (!x) head={a,b,c,x};
		else dq.pub({a,b,c,x});
	}
	
	curr=0;
	brute();
	
	//convert to state
	state[0]=head;
	rep(x,1,n) state[x]=dq[x-1];
	
	while (true){
		//cout<<"move: "<<moves-1<<endl;
		//rep(x,0,n) cout<<state[x].idx<<" "; cout<<endl;
		
		vector<ii> stk;
		
		//find the first instance where state[z].b<state[x].a
		//maintain min stack of state[z].b
		
		//now, we focus on the belt itself
		//there is a case where the red does not convert to a anything but the game ends
		//we need to handle that case carefully!
		//i think lets just insert it into stack with value -1
		//then if it appears its easily handled
		
		memset(green,false,sizeof(green));
		
		int cnt=0;
		
		int pidx=-1;
		rep(x,0,n){
			if (x && state[x-1].b>state[x].a){ //red
				
			}
			else{ //not red
				if (pidx!=-1 && state[pidx].c>state[x].a){
					green[pidx]=true;
				}
				
				pidx=x;
			}
		}
		if (state[pidx].c>state[0].a) green[0]=true;
		
		rep(x,0,n){
			if (x && state[x-1].b>state[x].a){ //red
				
			}
			else{ //not red
				int temp=green[x]?-1:state[x].b;
				
				while (!stk.empty() && stk.back().fi>temp) stk.pob();
				stk.pub(ii(temp,cnt));
				cnt++;
			}
		}
		
		int best=1e9; //shortest distance until red becomes not red
		int cnt2=cnt;
		
		//cout<<"non-reds: "<<cnt<<endl;
		
		rep(x,0,n){
			if (x && state[x-1].b>state[x].a){ //red
				if (stk.front().fi>state[x].a) continue; //it wont become red here
				
				int lo=0,hi=sz(stk),mi;
				while (hi-lo>1){
					mi=hi+lo>>1;
					if (stk[mi].fi<state[x].a) lo=mi;
					else hi=mi;
				}
				
				//cout<<"debug: "<<x<<endl;
				//for (auto &it:stk) cout<<it.fi<<"_"<<it.se<<" "; cout<<endl;
				//cout<<state[x].a<<endl;
				
				//cout<<"found: "<<pos[stk[hi]]<<endl;
				int dist=cnt2-stk[lo].se;
				//cout<<dist<<endl;
				if (dist<best){
					best=dist;
				}
				
				//cout<<endl;
				
			}
			else{ //not red
				int temp=green[x]?-1:state[x].b;
				
				while (!stk.empty() && stk.back().fi>temp) stk.pob();
				stk.pub(ii(temp,cnt2));
				cnt2++;
			}
		}
		
		//cout<<"number in belt: "<<cnt<<endl;
		//cout<<"d: "<<best<<" "<<idx<<endl;
		
		if (best==1e9){
			cout<<"-1 -1"<<endl;
			return 0;
		}
		
		//we simulate best-1 cycles for the reds
		
		best--;
		
		//cout<<"hmm: "<<endl;
		//cout<<best<<" "<<cnt<<endl;
		if (best>=0){
			moves+=best*(n-1);
			
			//cout<<endl;
			cnt2=0;
			rep(x,0,n){
				if (x && state[x-1].b>state[x].a){ //red
				
				}
				else{ //not red
					trans_belt[cnt2]=state[x];
					cnt2++;
				}
			}
			
			//rep(x,0,cnt2) cout<<trans_belt[x].idx<<" "; cout<<endl;
			
			rep(x,n,0){
				if (x && state[x-1].b>state[x].a){ //red
					
				}
				else{ //not red
					cnt2--;
					//cout<<x<<" "<<(cnt2-best+cnt)%cnt<<endl;
					state[x]=trans_belt[(cnt2-best+cnt)%cnt];
				}
			}
		}
		
		//cout<<cnt<<endl;
		//cout<<"move: "<<moves-1<<endl;
		//rep(x,0,n) cout<<state[x].idx<<" "; cout<<endl;
		
		head=state[0];
		dq.clear();
		rep(x,1,n) dq.pub(state[x]);
		
		curr=1;
		brute();
		
		//convert to state
		state[0]=head;
		rep(x,1,n) state[x]=dq[x-1];
		
		//cout<<"move: "<<moves-1<<endl;
		//rep(x,0,n) cout<<state[x].idx<<" "; cout<<endl;
		//cout<<endl;
		
		//break;
	}
}