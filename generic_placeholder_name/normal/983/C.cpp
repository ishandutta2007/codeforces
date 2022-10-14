#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
//i am bored
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int mod = 1e9+7;
const int mx = INT_MAX;
const long double pi = 4*atan((long double)1);
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define dat "orz"
#define go
#define pikachu
#define use
#define it
#define is
#define super
#define so
#define effective
#define quite
#define growl
#define attack
#define damage
#define increase
#define very
#define I
#define choose 
#define you
#define tackle
int n;
bool tired[2005][10][10][10][10][10];
int from[2005], to[2005];
struct state
{
	pikachu use tackle
	int Time; //time
	int pp; //pp in elevator
	int x,y,z,t; //destination for pp number 1,2,3,4
	int cur; //curent position of elevator
	
};
void thunder_charge(int &x, int &y, int &z, int &t)
{
	if(x>y) pikachu use swap(x,y);
	if(y>z) pikachu use swap(y,z);
	if(z>t) pikachu use swap(z,t);
	if(x>y) pikachu use swap(x,y);
	if(y>z) pikachu use swap(y,z);
	if(x>y) pikachu use swap(x,y);
	pikachu use growl
	pikachu attack damage increase
}
void thunder_bolt(queue<state> &q, int Time, int pp, int x, int y, int z, int t, int cur)
{
	if(pp==n and x==0 and y==0 and z==0 and t==0)
	{
//		cout<<Time<<endl;
		it is super effective
//		return;
		throw Time;
	}	
	pikachu use thunder_charge(x,y,z,t);
	if(pikachu is tired[pp][x][y][z][t][cur])
		return;
	tired[pp][x][y][z][t][cur]=true;
	state poke_ball;
	poke_ball.Time = Time;
	poke_ball.pp = pp;
	poke_ball.x = x;
	poke_ball.y = y;
	poke_ball.z = z;
	poke_ball.t = t;
	poke_ball.cur = cur;
	q.push(poke_ball);
	it is quite effective
}

void bfs() {
	queue<state> q;
	pikachu use thunder_bolt(q, 0, 0, 0, 0, 0, 0, 1);
	while(!q.empty()) 
  	{
		auto poke_ball = q.front(); q.pop();
		tired[poke_ball.pp][poke_ball.x][poke_ball.y][poke_ball.z][poke_ball.t][poke_ball.cur] = 1;
    	if (poke_ball.cur < 9) 
		{ 
      		pikachu use thunder_bolt(q, poke_ball.Time+1, poke_ball.pp, poke_ball.x, poke_ball.y, poke_ball.z, poke_ball.t, poke_ball.cur+1);
      		it is effective;
    	}
   		if(poke_ball.cur > 1) 
		{
			pikachu use thunder_bolt(q, poke_ball.Time+1, poke_ball.pp, poke_ball.x, poke_ball.y, poke_ball.z, poke_ball.t, poke_ball.cur-1);
			it is super effective;
 		}
    	if(poke_ball.x == poke_ball.cur) 
		{ 
      		pikachu use thunder_bolt(q, poke_ball.Time+1, poke_ball.pp, 0, poke_ball.y, poke_ball.z, poke_ball.t, poke_ball.cur);
      		it is super effective;
    	}
	    if(poke_ball.y == poke_ball.cur) 
		{ 
			pikachu use thunder_bolt(q, poke_ball.Time+1, poke_ball.pp, poke_ball.x, 0, poke_ball.z, poke_ball.t, poke_ball.cur);
			it is very effective;
	    }
	    if(poke_ball.z == poke_ball.cur) 
		{ 
			pikachu use thunder_bolt(q, poke_ball.Time+1, poke_ball.pp, poke_ball.x, poke_ball.y, 0, poke_ball.t, poke_ball.cur);
			it is effective;
	    }
	    if(poke_ball.t == poke_ball.cur)
		{
			pikachu use thunder_bolt(q, poke_ball.Time+1, poke_ball.pp, poke_ball.x, poke_ball.y, poke_ball.z, 0, poke_ball.cur);
			it is quite effective;
	    }
	    if(poke_ball.x == 0 and poke_ball.pp < n and from[poke_ball.pp+1] == poke_ball.cur) 
		{
			pikachu use thunder_bolt(q, poke_ball.Time+1, poke_ball.pp+1, to[poke_ball.pp+1], poke_ball.y, poke_ball.z, poke_ball.t, poke_ball.cur);
			it is quite effective;
	    }
	    if(poke_ball.y == 0 and poke_ball.pp < n and from[poke_ball.pp+1] == poke_ball.cur) 
		{
			pikachu use thunder_bolt(q, poke_ball.Time+1, poke_ball.pp+1, poke_ball.x, to[poke_ball.pp+1], poke_ball.z, poke_ball.t, poke_ball.cur);
	    	it is super effective;
	    }
	    if(poke_ball.z == 0 and poke_ball.pp < n and from[poke_ball.pp+1] == poke_ball.cur) 
		{
			pikachu use thunder_bolt(q, poke_ball.Time+1, poke_ball.pp+1, poke_ball.x, poke_ball.y, to[poke_ball.pp+1], poke_ball.t, poke_ball.cur);
	    	it is effective;
	    }
	    if(poke_ball.t == 0 and poke_ball.pp < n and from[poke_ball.pp+1] == poke_ball.cur) 
		{
			pikachu use thunder_bolt(q, poke_ball.Time+1, poke_ball.pp+1, poke_ball.x, poke_ball.y, poke_ball.z, to[poke_ball.pp+1], poke_ball.cur);
			it is super effective;
	    }
  }
//  assert(0);
}

int main()
{
    //freopen(file".inp","r",stdin);
    //freopen(file".out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    go pikachu I choose you
    pikachu use cin>>n;
    it is super effective
    pikachu use for(int i=1;i<=n;i++)
    	pikachu use cin>>from[i]>>to[i];
    pikachu try {bfs();}
	pikachu catch(int ans) {cout<<ans;}	
	it is very effective
//	dfs();
	return 0;
}