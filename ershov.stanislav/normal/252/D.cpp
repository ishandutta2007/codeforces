#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n, q[111], s[111], q2[111], a[111], k, ans=-1, ans2=-1;
int main()
{
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> q[i];
    for (int i=0; i<n; i++) cin >> s[i];
    for (int i=0; i<n; i++) a[i]=i+1;
    bool t=true;
    for (int i=0; i<n; i++) if (a[i]!= s[i]) t=false;
    if (t) ans=0;
    for (int i=0; i<k; i++) {
        for (int j=0; j<n; j++) q2[j]=a[q[j]-1];
        t=true;
        for (int j=0; j<n; j++) {
            a[j]=q2[j];
            if (s[j]!=q2[j]) t=false;
        }
        if (t&&ans==-1) ans=i+1;
    }
    for (int i=0; i<n; i++) q2[q[i]-1]=i+1;
    for (int i=0; i<n; i++) q[i]=q2[i];
    for (int i=0; i<n; i++) a[i]=i+1;
    for (int i=0; i<k; i++) {
        for (int j=0; j<n; j++) q2[j]=a[q[j]-1];
        t=true;
        for (int j=0; j<n; j++) {
            a[j]=q2[j];
            if (s[j]!=q2[j]) t=false;
        }
        if (t&&ans2==-1) ans2=i+1;
    }
    if (ans==-1&&ans2==-1||ans==0) cout << "NO";
    else if (ans>1&&ans<=k&&(k-ans)%2==0) cout << "YES";
    else if (ans2>1&&ans2<=k&&(k-ans2)%2==0) cout << "YES";
    else if (ans==1&&k==1) cout << "YES";
    else if (ans==1&&(ans2==-1||ans2>1)&&(k-1)%2==0) cout << "YES";
    else if (ans2==1&&k==1) cout << "YES";
    else if (ans2==1&&(ans==-1||ans>1)&&(k-1)%2==0) cout << "YES";
    else cout << "NO";
    return 0;
}