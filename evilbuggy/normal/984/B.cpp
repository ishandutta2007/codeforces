#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    string s;
    cin>>n>>m;
    int a[n+2][m+2];
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++){
        cin>>s;
        for(int j = 0; j < m; j++){
            if(s[j] >= '1' && s[j] <= '8'){
                a[i][j+1] = s[j] - '0';
            }else if(s[j] == '.'){
                a[i][j+1] = 0;
            }else{
                a[i][j+1] = 9;
            }
        }
    }
    bool ans = true;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 9)continue;
            int tt = 0;
            for(int x = -1; x < 2; x++){
                for(int y = -1; y < 2; y++){
                    if(x == 0 && y == 0)continue;
                    if(a[x+i][y+j] == 9){
                        tt++;
                    }
                }
            }
            if(tt != a[i][j]){
                ans = false;
                break;
            }
        }
        if(!ans)break;
    }
    if(ans){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}