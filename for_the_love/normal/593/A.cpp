#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

string s[N];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int ans = 0;
    for (char a = 'a'; a <= 'z'; a++)
    for (char b = a + 1; b <= 'z'; b++){
        int sum = 0;
        for (int i = 0; i < n; i++){
            int flag = 0;
            for (int j = 0; j < s[i].size(); j++)
            if (s[i][j] != a && s[i][j] != b){
                flag = 1;
                break;
            }
            if (!flag) sum += s[i].size();
        }
        ans = max(ans, sum);
    }
    printf("%d\n", ans);

}