#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];

vector < char > le(int l, int r, int pre)
{
        vector < char > res;
        while(l <= r && a[l] > pre){
                res.push_back('L');
                pre = a[l++];
        }
        return res;
}

vector < char > re(int l, int r, int pre)
{
        vector < char > res;
        while(l <= r && a[r] > pre){
                res.push_back('R');
                pre = a[r--];
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        vector < char > res;
        int l = 1, r = n, pre = 0;
        while(l <= r){
                if(max(a[l], a[r]) <= pre){
                        break;
                }
                if(a[l] == a[r]){
                        vector < char > a = le(l, r, pre);
                        vector < char > b = re(l, r, pre);
                        if(b.size() > a.size()){
                                a = b;
                        }
                        for(char c: a){
                                res.push_back(c);
                        }
                        break;
                }
                if(a[l] < a[r]){
                        if(a[l] > pre){
                                res.push_back('L');
                                pre = a[l++];
                        } else{
                                res.push_back('R');
                                pre = a[r--];
                        }
                } else{
                        if(a[r] > pre){
                                res.push_back('R');
                                pre = a[r--];
                        } else{
                                res.push_back('L');
                                pre = a[l++];
                        }
                }
        }

        cout << res.size() << "\n";
        for(char c: res){
                cout << c;
        }
}