#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

long long n, d, last, last_x;
vector < long long > v;

bool can(long long x)
{
    if(x == -1){
        if(d == -1e9)
            return true;
        long long g = ((long long)v.size() - last);
        return last_x + d * g > 0;
    }
    if(last_x != -1){
        if(d != -1e9){
            long long d2 = (x - last_x) / ((long long)v.size() - last);
            if(d2 != d)
                return false;
        }
        if((x - last_x) % ((long long)v.size() - last) != 0)
            return false;
        d = (x - last_x) / ((long long)v.size() - last);
        if(x - (long long)v.size() * d < 1)
            return false;
    }
    last_x = x;
    last = v.size();
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    long long cnt = 0;
    for(long long i = 1; i <= n; i++){
        long long x;
        cin >> x;
        if(!v.empty() && can(x)){
            v.pb(x);
        }
        else{
            cnt++;
            v.clear();
            last = 0;
            last_x = x;
            d = -1e9;
            v.pb(x);
        }
    }
    cout << cnt << endl;
}