#include <iostream>
#include <vector>

using namespace std;
int n, x[111111];
int main()
{
    int min=1<<30, max=-1, mini, maxi, av=-1;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i];
        if (x[i]>max) max=x[i], maxi=i;
        if (x[i]<min) min=x[i], mini=i;
    }
    for (int i=0; i<n; i++) if (x[i]!=max&&x[i]!=min) av=i;
    if (av!=-1) {
        if (maxi<n-1&&x[maxi+1]!=min) cout << maxi+2 << ' ' << mini+1;
        else if (maxi>0&&x[maxi-1]!=min) cout << maxi << ' ' << mini+1;
        else if (maxi<n-1) cout << maxi+1 << ' ' << maxi+2;
        else cout << maxi << ' ' << maxi+1;
    } else if (max==min) cout << -1;
    else if (n<=2) cout << -1;
    else {
        int ca=0, cb=0, first=-1;
        for (int i=0; i<n; i++) {
            if (x[i]==x[0])ca++;
            else cb++;
            if (x[i]!=x[0]&&first==-1) first=i;
        }
        if (cb>1) cout << 1 << ' ' << first+1;
        else if (first!=1) cout << 2 << ' ' << first+1;
        else if (first!=n-2) cout << n-1 << ' ' << first+1;
        else cout << -1;
    }
    return 0;
}