#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back

struct Path {
    int a,b,c;
};

const int nax = 1000+10;
int n,dep[nax],root,deg[nax];
vi leaf[nax];
vi S;
vector<pii>V[nax];
vector<Path>moves;

void dfs(int x,int p) {
    dep[x] = dep[p]+1;
    S.PB(x);
    for(auto nbh:V[x]) {
        if(nbh.ST!=p) {
            dfs(nbh.ST,x);
            leaf[x].PB(S.back());
        }
    }
}

void dfs2(int x,int p) {
    for(auto nbh:V[x]) {
        if(nbh.ST!=p) {
            if(deg[nbh.ST]==1) {
                moves.PB({nbh.ST,root,nbh.ND});
                if(x!=root) {
                moves.PB({root,leaf[x][0],-nbh.ND/2});
                moves.PB({root,leaf[x][1],-nbh.ND/2});
                moves.PB({leaf[x][0],leaf[x][1],nbh.ND/2});
                }
            }
            else {
                moves.PB({root,leaf[nbh.ST][0],nbh.ND/2});
                moves.PB({root,leaf[nbh.ST][1],nbh.ND/2});
                moves.PB({leaf[nbh.ST][0],leaf[nbh.ST][1],-nbh.ND/2});
                if(x!=root) {
                moves.PB({root,leaf[x][0],-nbh.ND/2});
                moves.PB({root,leaf[x][1],-nbh.ND/2});
                moves.PB({leaf[x][0],leaf[x][1],nbh.ND/2});
                }
            }
            dfs2(nbh.ST,x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	for(int a,b,c,i=1; i<n;i++) {
        cin>>a>>b>>c;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
        deg[a]++; deg[b]++;
	}
	for(int i=1; i<=n;i++) {
        if(deg[i]==2) {
            cout<<"NO";
            return 0;
        }
        if(deg[i]==1) {
            root=i;
        }
	}
	cout<<"YES\n";
	dfs(root,0);
	dfs2(root,0);
	cout<<moves.size()<<"\n";
	for(auto it:moves) {
        cout<<it.a<<" "<<it.b<<" "<<it.c<<"\n";
	}
}