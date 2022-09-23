#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1000010;

using namespace std;

int n;
char c[N];
vector < long long > l, r;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d\n%s\n", &n, &c);
    for(int i = 0; i < n; i++){
        if(c[i] == 'U')
            l.pb(i);
        else
            r.pb(n - i - 1);
    }
    r.pb(0);
    for(int i = 1; i < l.size(); i++)
        l[i] += l[i - 1];
    for(int i = r.size() - 2; i >= 0; i--)
        r[i] += r[i + 1];
    int hl = 0,
        hr = 0;
    for(int i = 0; i < n; i++){
        long long ans = -1;
        if(c[i] == 'D' && hl == 0){
            pr("%d ", i + 1);
            hr++;
            continue;
        }
        else if(c[i] == 'U' && r.size() - hr - 1 == 0){
            pr("%d ", n - i);
            hl++;
            continue;
        }
        if(c[i] == 'U'){
            if(hl < r.size() - hr - 1){
                ans = 1ll * i * (hl + 1) - l[hl];
                ans = ans + 1ll * (n - i - 1) * (hl + 1) - (r[hr] - r[hr + hl + 1]);
                ans = ans * 2ll + i + 1;
            }
            else{
                ans = 1ll * i * (r.size() - hr) - l[hl];
                if(hl - r.size() + hr >= 0 && hl - r.size() + hr < l.size())
                    ans += l[hl - r.size() + hr];
                ans = ans + 1ll * (n - i - 1) * (r.size() - hr - 1) - (r[hr]);
                ans = ans * 2ll + (n - i);
            }
            hl++;
        }
        else{
            if(hl <= r.size() - hr - 2){
                ans = 1ll * i * hl - l[hl - 1];
                ans = ans + 1ll * (n - i - 1) * (hl + 1) - (r[hr] - r[hr + hl + 1]);
                ans = ans * 2ll + i + 1;
            }
            else{
                ans = 1ll * i * (r.size() - hr - 1) - l[hl - 1];
                if(hl - r.size() + hr >= 0 && hl - r.size() + hr < l.size())
                    ans += l[hl - r.size() + hr];
                ans = ans + 1ll * (n - i - 1) * (r.size() - hr - 1) - (r[hr]);
                ans = ans * 2ll + (n - i);
            }
            hr++;
        }
        pr("%I64d ", ans);
    }
}