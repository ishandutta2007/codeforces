#include <iostream>
#include <string>

using namespace std;
int d[111], t, m, c, b=0, i, j, k, l;
string s;
int main()
{
    cin >> t >> m;
    for (int k=0; k<t; k++) {
        cin >> s;
        if (s[0]=='a') {
            cin >> c;
            for (i=0, j=-1; i<m; i++) if (i-j==c&&!d[i]) break;
            else if (d[i]) j=i;
            if (i-j==c&&i<m) {
                cout << ++b << endl;
                for (l=j+1; l<=i; l++) d[l]=b;
            }
            else cout << "NULL" << endl;
        } else if (s[0]=='e') {
            cin >> c;
            for (i=0, j=0; i<m; i++) if (d[i]==c&&c!=0) d[i]=0, j=1;
            if (!j) cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
        }
        else if (s[0]=='d') {
            for (i=0, j=0; i<m; i++) if (d[i]) l=d[j], d[j]=d[i], d[i]=l, j++;
        }
    }
    return 0;
}