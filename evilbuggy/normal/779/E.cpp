#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    map<string,int> index;
    index["?"] = 0;
    int a[n+1][m][2];
    for(int i = 0; i < m; i++){
        a[0][i][0] = 0;
        a[0][i][1] = 1;
    }
    string variable, op1, op2, oper;
    for(int i = 1; i <= n; i++){
        cin>>variable;
        index[variable] = i;
        cin>>op1;
        cin>>op1;
        if(op1[0] == '0' || op1[0] == '1'){
            for(int j = 0; j < m; j++){
                a[i][j][0] = op1[j] - '0';
                a[i][j][1] = op1[j] - '0';
            }
        }else{
            cin>>oper>>op2;
            int i1 = index[op1];
            int i2 = index[op2];
            for(int j = 0; j < m; j++){
                if(oper[0] == 'X'){
                    a[i][j][0] = a[i1][j][0]^a[i2][j][0];
                    a[i][j][1] = a[i1][j][1]^a[i2][j][1];
                }else if(oper[0] == 'A'){
                    a[i][j][0] = a[i1][j][0]&a[i2][j][0];
                    a[i][j][1] = a[i1][j][1]&a[i2][j][1];
                }else{
                    a[i][j][0] = a[i1][j][0]|a[i2][j][0];
                    a[i][j][1] = a[i1][j][1]|a[i2][j][1];
                }
            }
        }
    }
    int ans[m][2];
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            ans[j][0] += a[i][j][0];
            ans[j][1] += a[i][j][1];
        }
    }
    for(int i = 0; i < m; i++){
        if(ans[i][0] <= ans[i][1])cout<<0;
        else cout<<1;
    }
    cout<<endl;
    for(int i = 0; i < m; i++){
        if(ans[i][0] >= ans[i][1])cout<<0;
        else cout<<1;
    }
    cout<<endl;
}