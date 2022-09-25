#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

const int MOD=998244353;

ll n,m,l,r;

vector<vector<long long> > mul(vector<vector<long long> > i, vector<vector<long long> > j,int m){
    vector<vector<long long> > res;
    for (int x=0;x<i.size();x++){
        res.push_back(vector<long long>());
        for (int y=0;y<i.size();y++){
            res[x].push_back(0);
            for (int z=0;z<i.size();z++){
                res[x][y]=(res[x][y]+i[x][z]*j[z][y])%m;
            }
        }
    }
    return res;
}

vector<vector<long long> > mexp(vector<vector<long long> > mat,long long p,int m){
    if (p==1) return mat;
    vector<vector<long long> > res=mexp(mat,p>>1,m);
    res=mul(res,res,m);
    if (p&1) res=mul(res,mat,m);
    return res;
}


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin>>n>>m>>l>>r;
	
	ll o=(r+1)/2-l/2;
	ll e=r/2-(l-1)/2;
	
	//cout<<o<<" "<<e<<endl;
	
	vector<vector<ll> > v={{o,e},{e,o}};
	
	v=mexp(v,n*m,MOD);
	
	//cout<<v[0][0]<<" "<<v[0][1]<<endl;
	//cout<<v[1][0]<<" "<<v[1][1]<<endl;
	
	if ((n*m)%2==1) cout<<(v[0][0]+v[0][1])%MOD<<endl;
	else cout<<v[0][0]<<endl;
}