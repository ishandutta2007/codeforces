#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define endl '\n'

#define rep(x,s,e) for (auto x=s-(s>e);x!=e-(s>e);(s<e?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

string s;
int k;

vector<int> bad;

int aho[10005][2];
int pi[10005]; //kmp failure function

int pos[2605]; //keep track of current pos in trie

int IDX=1;

void build_aho(){
    memset(aho,-1,sizeof(aho));
    memset(pos,0,sizeof(pos));
    
    pi[0]=0;
	
    rep(x,k,0){ //for all character position (bfs)
        rep(y,0,sz(bad)){
            int curr=pos[y];
			int nxt=(bad[y]&(1<<x)?1:0);
            if (aho[curr][nxt]==-1){
                int fail=pi[curr];
                while (fail>0){
                    if (aho[fail][nxt]!=-1) break;
                    fail=pi[fail];
                }
                if (aho[fail][nxt]!=-1){
                    fail=aho[fail][nxt];
                }
                
                pi[IDX]=fail;
                aho[curr][nxt]=IDX;
                
                IDX++;
            }
            
			pos[y]=aho[curr][nxt];
        }
    }
}

int add(int pos,int nxt){
	while (pos){
		if (aho[pos][nxt]!=-1) break; 
		pos=pi[pos];
	}
	if (aho[pos][nxt]!=-1) return aho[pos][nxt];
	else return pos;
}

int memo[2][10005];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin>>s;
	cin>>k;
	
	rep(x,0,(1<<k)){
		if (x&(1<<(k-1))){
			rep(div,1,k) if (k%div==0){
				if (x&(1<<(div-1))){
					goto ok;
				}
				
				rep(y,0,k-div) if ((x&(1<<y))!=0 && (x&(1<<(y+div)))!=0){
					goto ok;
				}
			}
			bad.push_back(x);
		}
		ok:;
	}
	
	build_aho();
	
	int a=0,b=1;
	memset(memo[a],63,sizeof(memo[a]));
	memo[a][0]=0;
	
	rep(pos,0,sz(s)){
		memset(memo[b],63,sizeof(memo[b]));
		
		rep(x,0,IDX){
			memo[b][x]=min(memo[b][x],memo[a][x]+1);
			int curr=x;
			curr=add(curr,1);
			rep(zzz,0,(int)s[pos]-'1') curr=add(curr,0);
			if (aho[curr][0]!=-1 || aho[curr][1]!=-1)
				memo[b][curr]=min(memo[b][curr],memo[a][x]);
		}
		
		//rep(x,0,IDX) cout<<memo[b][x]<<" "; cout<<endl;
		swap(a,b);
	}
	
	int ans=1e9;
	rep(x,0,10005) ans=min(ans,memo[a][x]);
	cout<<ans<<endl;
}