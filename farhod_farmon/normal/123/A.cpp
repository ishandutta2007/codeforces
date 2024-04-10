#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const int Q = 1000010;

using namespace std;

string s;
int c[200];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> s;
        vector < int > A, B;
        for(int i = 1; i <= s.size(); i++){
                bool good = true;
                for(int j = 2; j * j <= i; j++){
                        if(i % j == 0){
                                good = false;
                                break;
                        }
                }
                if(!good){
                        A.push_back(i - 1);
                } else{
                        if(i != 1 && i * 2 <= s.size()){
                                A.push_back(i - 1);
                        } else{
                                B.push_back(i - 1);
                        }
                }
        }

        for(int i = 0; i < s.size(); i++){
                c[s[i]] += 1;
        }

        bool good = false;
        for(int i = 'a'; i <= 'z'; i++){
                if(c[i] >= A.size()){
                        c[i] -= A.size();
                        for(int j = 0; j < A.size(); j++){
                                s[A[j]] = i;
                        }
                        good = true;
                        break;
                }
        }

        if(!good){
                cout << "NO" << "\n";
                return 0;
        }
        for(int i = 'a'; i <= 'z'; i++){
                for(int j = 0; j < c[i]; j++){
                        s[B.back()] = i;
                        B.pop_back();
                }
        }

        cout << "YES" << "\n";
        cout << s << "\n";
}