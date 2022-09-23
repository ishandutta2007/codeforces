#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 110;

using namespace std;

long long r;
long long a[3];
long long n[3];
long long p[3];
string s;

bool f(long long x)
{
    long long cnt = 0;
    for(int i = 0; i < 3; i++){
        long long g = a[i] * x;
        cnt += max(0ll, g - n[i]) * p[i];
        if(cnt > r)
            return false;
    }
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'B')
            a[0]++;
        else if(s[i] == 'S')
            a[1]++;
        else
            a[2]++;
    }
    cin >> n[0] >> n[1] >> n[2];
    cin >> p[0] >> p[1] >> p[2];
    cin >> r;
    long long l = 0,
              r = 1e15;
    while(l < r){
        long long m = (l + r) / 2;
        if(f(m + 1))
            l = m + 1;
        else
            r = m;
    }
    cout << l << endl;
}