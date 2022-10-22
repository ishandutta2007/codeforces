#include <bits/stdc++.h>

using namespace std;

int n;
string row;
bool matrix[5201][5201];
int sum[5201][5201];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>row;
        for(int j=3; j<n; j+=4) {
            int help = j,num;
            char c = row[j/4];
            if(48<=c&&c<=48+9) num = atoi(&c);
            else num = c-65+10;
            while(help>j-4) {
                if(num&1) matrix[i][help]=1;
                num/=2;
                help--;
            }
        }
    }
    for(int i=0; i<n;i++) {
        for(int j=0; j<n;j++) {
            if(i>0) sum[i][j]+=sum[i-1][j];
            if(j>0) sum[i][j]+=sum[i][j-1];
            if(i>0&&j>0) sum[i][j]-=sum[i-1][j-1];
            sum[i][j]+=matrix[i][j];
        }
    }
    for(int x=1; x<=n;x++) {
        if(n%x!=0) continue;
        bool ok=1;
        for(int i=x-1; i<n; i+=x) {
            for(int j=x-1; j<n; j+=x) {
                int act = sum[i][j];
                if(i-x>=0) act-=sum[i-x][j];
                if(j-x>=0) act-=sum[i][j-x];
                if(i-x>=0&&j-x>=0) act+=sum[i-x][j-x];
                if(act!=0&&act!=x*x) {
                    ok=0; i=n; break;
                }
            }
        }
        if(ok) ans=x;
    }
    cout<<ans;
    return 0;
}