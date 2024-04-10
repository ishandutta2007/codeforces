#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

char s[1000005];
char stmp[1000005];
char t[1000005];

struct Perm{
	vector<int> perm;

	Perm concat(Perm other){
		Perm p;
		p.perm=vector<int>(perm.size());
		for(int i=0; i < perm.size(); ++i)
			p.perm[i]=perm[other.perm[i]];
		return p;
	}

	Perm inv(){
		Perm p;
		p.perm=vector<int>(perm.size());
		for(int i=0; i < perm.size(); ++i)
			p.perm[perm[i]]=i;
		return p;
	}
};

int main(){
	int m, n;
	scanf("%s", s);
	n=strlen(s);
	scanf("%d", &m);
	rep(zi,0,m){
		int k, d;
		scanf("%d%d", &k, &d);
		Perm p;
		for(int i=0; i < d; ++i)
			for(int j=i; j < k; j += d)
				if(j)
					p.perm.push_back(j);
		p.perm.push_back(0);
		int j=0;
		for(int i=0; i < k; ++i)
			t[i]=s[i];
		for(int i=0; i < n-k+1; ++i){
			stmp[i]=t[j];
			t[j]=s[i+k];
			j=p.perm[j];
		}
		Perm q;
		for(int i=0; i < k; ++i){
			q.perm.push_back(i);
		}
		for(int i=0; i < 20; ++i){
			if((n-k+1)&(1<<i))
				q=q.concat(p);
			if((1<<i) > (n-k+1))
				break;
			p=p.concat(p);
		}
		for(int i=n-k+1; i < n; ++i){
			stmp[i]=t[q.perm[i-(n-k+1)]];
			//stmp[i]=s[i-(n-k)+q.perm[i-(n-k)];
		}
		for(int i=0; i < n; ++i)
			s[i]=stmp[i];
		printf("%s\n", s);
	}
}