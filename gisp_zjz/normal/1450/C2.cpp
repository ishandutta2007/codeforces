#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
typedef vector<int>vi;
const int maxn=1e6+100;
const int M=1000000007;
int n,_,tot,sum,id;
char s[505][505],t[6][505][505];
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        sum=tot=0;
        for (int i=0;i<n;i++) cin >> s[i];
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                sum+=s[i][j]!='.';
        bool flag=0;
        for (int x=0;x<3;x++)
        for (int y=0;y<3;y++){
            if (x==y) continue;
            if (flag) continue;
            tot=0;
            for (int i=0;i<n;i++)
            for (int j=0;j<n;j++) if (s[i][j]!='.'){
                if ((i+j)%3==x) tot+=s[i][j]!='X';
                if ((i+j)%3==y) tot+=s[i][j]!='O';
            }
            if (tot<=sum/3){
                flag=1;
                for (int i=0;i<n;i++)
                for (int j=0;j<n;j++) if (s[i][j]!='.'){
                    if ((i+j)%3==x) s[i][j]='X';
                    if ((i+j)%3==y) s[i][j]='O';
                }
            }
        }
        for (int i=0;i<n;i++) cout << s[i] << endl;
    }
    return 0;
}