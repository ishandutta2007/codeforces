#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3003;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                string s, a = "", b = "";
                cin >> s;
                for(char c: s){
                        if(c % 2){
                                a += c;
                        } else{
                                b += c;
                        }
                }
                string res = "";
                if(a == "" || b == ""){
                        cout << s << "\n";
                        continue;
                }

                for(int i = 0; i < a.size(); i++){
                        bool good = false;
                        for(int j = 0; j < b.size(); j++){
                                if(abs(a[i] - b[j]) > 1){
                                        good = true;
                                        for(int h = 0; h < a.size(); h++){
                                                if(h == i){
                                                        continue;
                                                }
                                                res += a[h];
                                        }
                                        res += a[i];
                                        res += b[j];
                                        for(int h = 0; h < b.size(); h++){
                                                if(h == j){
                                                        continue;
                                                }
                                                res += b[h];
                                        }
                                        break;
                                }
                        }
                        if(good){
                                break;
                        }
                }
                if(res == ""){
                        res = "No answer";
                }

                cout << res << "\n";
        }
}