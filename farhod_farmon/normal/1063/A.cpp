#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10001;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

void solve()
{
        int n;
        cin >> n;
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        cout << s << "\n";
        /*int cnt = 0;
        for(int i = 0; i < s.size(); i++){
                string t = "";
                for(int j = i; j < s.size(); j++){
                        t += s[j];
                        bool gg = true;
                        for(int h =0; h < t.size();h++){
                                if(t[h]!=t[t.size()-h-1]){
                                        gg=0;
                                }
                        }
                        cnt+=gg;
                }
        }
        cout<<cnt;*/
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("distance.in");
        //fout("distance.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}