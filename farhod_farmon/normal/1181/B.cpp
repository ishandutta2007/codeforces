#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
char a[N];

string get(int x)
{
        vector < int > A, B;
        for(int i = x; i > 0; i--){
                A.push_back(a[i] - '0');
        }
        for(int i = n; i > x; i--){
                B.push_back(a[i] - '0');
        }
        while(A.size() < B.size()) A.push_back(0);
        while(B.size() < A.size()) B.push_back(0);
        A.push_back(0);
        for(int i = 0; i < B.size(); i++){
                A[i] += B[i];
                A[i + 1] += A[i] / 10;
                A[i] %= 10;
        }
        while(A.back() == 0) A.pop_back();
        string res = "";
        while(!A.empty()){
                res += char(A.back() + '0');
                A.pop_back();
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        string res = "";
        vector < int > v;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                res += "9";
                if(i < n){
                        v.push_back(i);
                }
        }
        sort(v.begin(), v.end(), [&](int x, int y){
                return abs(x - n / 2) > abs(y - n / 2);
             });
        for(int i = 0; i < 10; i++){
                while(!v.empty() && a[v.back() + 1] == '0'){
                        v.pop_back();
                }
                if(v.empty()){
                        break;
                }
                string can = get(v.back());
                v.pop_back();
                if(can.size() < res.size() || can.size() == res.size() && can < res){
                        res = can;
                }
        }
        cout << res << "\n";
}