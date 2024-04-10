//WTF deadlycritic
//lmao
//subbing this so that if I need to find this in the future I can find it

#include <bits/stdc++.h>

using namespace std;

#define fios        ios::sync_with_stdio(false), cin.tie(), cout.tie();
#define fr          first
#define sc          second
#define all(v)      v.begin(), v.end()
#define scan(a, n)  for(int i = 0; i < n; i++)cin >> a[i];
#define print(a, n) for(int i = 0; i < n; i++)cout << a[i] << ' '; cout << '\n';

typedef long long ll;
typedef pair<int, int> pt;

const int MN = 3e5+7;

int a[MN], n;

void inp(){
    cin >> n;
    scan(a, n);
}

int f(int l, int r){
    if(l == r)return 0;
    int sw = 1, ssw = 1;
    for(int i = l+1; i <= r; i++)if(a[i] < a[i-1])sw = 0;
    for(int i = l+1; i <= r; i++)if(a[i] > a[i-1])ssw = 0;

    if(sw == 1 || ssw == 1){
        for(int i = l; i <= r; i+=2)a[i] = -a[i];
        return ((r-l)&1);
    }

    int ii = -3;
    for(int i = l+1; i < r; i++){
        if(a[i] >= a[i-1] && a[i] >= a[i+1]){
            ii = i;
            break;
        }
    }
    if(ii == -3){
        for(int i = l; i <= r; i+=2)a[i] = -a[i];
        return ((r-l)&1);
    }
    int le = f(l, ii-1), re = f(ii+1, r);

    if(abs(le+re) > 1){
        for(int i = l; i < ii; i++)a[i] = -a[i];
        return 0;
    }
    return le+re;
}

void slv(){
    for(int i = 0; i < n; i++)a[i] = abs(a[i]);
    f(0, n-1);
    print(a, n);
}

signed main()
{
    int t = 1;
    cin >> t;
    while(t--){
        inp();
        slv();
    }
    return 0;
}