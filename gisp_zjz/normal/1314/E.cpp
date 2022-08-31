#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int M=998244353;
typedef vector<int> vi;
vi a;
int s2[50000],dp[2050][2050],n,k,cnt;
void print(vi b){
    for (auto x:b)cout<<x<<' ';cout<<endl;
}
int calc(vi b){
    //printf("F ");print(b);
    int sum=0,p=0,m=b.size();
    for (int i=0;i<m;i++){
        sum+=(s2[p+b[i]]-s2[p])*(m-i);
        p+=b[i];
    }
    return sum;
}
vi work(vi b){
    vi tmp; tmp.clear();
    int m=b.size();
    for (int i=1;i<=m;i++)
        for (int j=0;j<b[m-i];j++)
            tmp.pb(i);
    return tmp;
}
void dfs(int pos){
    int st;
    if (pos==0) st=1; else st=a[pos-1];
    for (int j=st;;j++){
        a.pb(j);
        vi res=a;
        //print(res);
        for (int _=0;_<k;_++){
            res=work(res);
            //print(res); //cout<<calc(res)<<endl;
            if (calc(res)>n) break;
        }
        //uts("H");
        if (calc(res)>n) break;
        cnt++;
        dfs(pos+1);
        a.resize(pos);
    }
}

int main(){
    for (int i=1;i<20000;i++) s2[i]=s2[i-1]+i;
    cin >> n >> k; a.clear();
    if (k==1){
        dp[1][1]=1;
        for (int i=2;i<=n;i++)
            for (int j=1;j<=i;j++)
                dp[i][j]=(dp[i-j][j]+dp[i-1][j-1])%M;
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=i;j++)
                ans=(ans+dp[i][j])%M;
        cout << ans << endl;
    } else if (k==2){
        dp[1][1]=1;
        for (int i=2;i<=n;i++)
            for (int j=1;j*(j+1)/2<=i;j++)
                dp[i][j]=(dp[i-s2[j]][j]+dp[i-j][j-1])%M;
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=i;j++)
                ans=(ans+dp[i][j])%M;
        cout << ans << endl;
    } else {
        k-=3;
        dfs(0);
        cout << cnt << endl;
    }
}