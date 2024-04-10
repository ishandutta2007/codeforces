#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e6+5;

vector<pii > w;
set<int> s;
int in[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    RI(i, n) {
        cin >> in[i];
        w.pb(mp(in[i], i));
    }
    RE(i, n+2) s.insert(i);
    ll res = 0;
    sort(w.begin(), w.end());
    ll mnoznik = n - 2;
    ll wyciete = 0;
    RE(i, n - 2) {
        int a = w[i].st, id = w[i].nd;
        res += mnoznik * (   ((ll)a)  - wyciete );
        wyciete = a;
        mnoznik--;
        int mniejsza = inf;
        set<int> :: iterator it = s.find(id);
        it++;
        int pom = *it;
        mini(mniejsza, in[pom]);
        it--;
        it--;
        pom = *it;
        mini(mniejsza, in[pom]);
        res += max(0LL, ((ll) mniejsza) - wyciete);
        s.erase(id);
    }
    cout << res;
    return 0;
}