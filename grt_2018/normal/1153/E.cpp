#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

int n;
vi validCol,validRow;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin>>n;
    for(int i=1; i<=n;i++) {
        cout<<"? "<<i<<" 1 "<<i<<" "<<n<<"\n";
        fflush(stdout);
        int x;
        cin>>x;
        if(x%2==1) validRow.PB(i);
    }
    for(int i=1; i<=n;i++) {
        cout<<"? 1 "<<i<<" "<<n<<" "<<i<<"\n";
        fflush(stdout);
        int x;
        cin>>x;
        if(x%2==1) validCol.PB(i);
    }
    if(validCol.size()==2&&validRow.size()==2) {
        vector<pi>ans;
        for(auto f:validRow) {
            for(auto s:validCol) {
                cout<<"? "<<f<<" "<<s<<" "<<f<<" "<<s<<"\n";
                fflush(stdout);
                int x;
                cin>>x;
                if(x==1) {
                    ans.PB({f,s});
                }
            }
        }
        cout<<"! ";
        for(auto it:ans) {
            cout<<it.ST<<" "<<it.ND<<" ";
        }
        fflush(stdout);
    }
    else {
        if(validCol.size()==0) {
            int pocz=1,kon=n,sr;
            while(pocz<=kon) {
                sr=(pocz+kon)/2;
                cout<<"? "<<validRow[0]<<" 1 "<<validRow[0]<<" "<<sr<<"\n";
                fflush(stdout);
                int x;
                cin>>x;
                if(x%2==1) {
                    kon = sr-1;
                }
                else pocz=sr+1;
            }
            cout<<"! "<<validRow[0]<<" "<<kon+1<<" "<<validRow[1]<<" "<<kon+1<<"\n";
            fflush(stdout);
        }
        else {
            int pocz=1,kon=n,sr;
            while(pocz<=kon) {
                sr=(pocz+kon)/2;
                cout<<"? 1 "<<validCol[0]<<" "<<sr<<" "<<validCol[0]<<"\n";
                fflush(stdout);
                int x;
                cin>>x;
                if(x%2==1) {
                    kon = sr-1;
                }
                else pocz=sr+1;
            }
            cout<<"! "<<kon+1<<" "<<validCol[0]<<" "<<kon+1<<" "<<validCol[1]<<"\n";
            fflush(stdout);
        }
    }
}