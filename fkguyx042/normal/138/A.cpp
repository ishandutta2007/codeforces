#include <bits/stdc++.h>

typedef long long int li;

#define min(a,b) a<=b?a:b
#define max(a,b) a>=b?a:b
#define Fi(i, st, ft) for(i = st;i <= ft; ++i)
#define Fd(i, st, ft) for(i = st;i >= ft; --i)
#define pb(a, b) a.push_back(b)
#define mod 1000000007
#define mp make_pair
#define MAXN 1500000
#define MX 1450000
#define inf 1000000000000000000ll
const int maxBufSize = (10000000);

using namespace std;

li n , k;
string scheme[3005];

string get_suffix(string temp)
{
    li i , a , len;
    string ret = "";
    a = 0;
    len = temp.length();
    i = len-1;
    while(i >= 0 && a < k) {
        if(temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u') {
            a++;
        }
        if(a == k) {
            ret = temp.substr(i , len-i);
            break;
        }
        i--;
    }
    return ret;
}

string getScheme1(string s1 , string s2 , string s3 , string s4)
{
    li i , j , a;
    a = 1;
    if(s1 == s2 && s1 == s3 && s1 == s4 && s2 == s3 && s2 == s4 && s3 == s4) {
        return "aaaa";
    } else {
        return "";
    }
}

string getScheme2(string s1 , string s2 , string s3 , string s4)
{
    li i , j , a;
    a = 1;
    if(s1 == s2 && s3 == s4 && s1 != s3) {
        return "aabb";
    } else {
        return "";
    }
}

string getScheme3(string s1 , string s2 , string s3 , string s4)
{
    li i , j , a;
    a = 1;
    if(s1 == s3 && s2 == s4 && s2 != s3) {
        return "abab";
    } else {
        return "";
    }
}

string getScheme4(string s1 , string s2 , string s3 , string s4)
{
    li i , j , a;
    a = 1;
    if(s1 == s4 && s2 == s3 && s1 != s2) {
        return "abba";
    } else {
        return "";
    }
}

int main()
{
    li i , j , a , b , c , chk;
    string s1 , s2 , s3 , s4 , s;
    cin >> n >> k;
    chk = 1;
    Fi(i , 1 , n) {
        cin >> s1 >> s2 >> s3 >> s4;
        s1 = get_suffix(s1);
        s2 = get_suffix(s2);
        s3 = get_suffix(s3);
        s4 = get_suffix(s4);
        //cout << s1 << " "  << s2 << " " << s3 << " " << s4 << "\n";
        if(s1 == "" || s2 == "" || s3 == "" || s4 == "") {
            chk = 0;
            break;
        }
        s = "";
        s = getScheme1(s1 , s2 , s3 , s4);
        if(s != "") {
            scheme[i] = s;
            continue;
        }
        s = getScheme2(s1 , s2 , s3 , s4);
        if(s != "") {
            scheme[i] = s;
            continue;
        }
        s = getScheme3(s1 , s2 , s3 , s4);
        if(s != "") {
            scheme[i] = s;
            continue;
        }
        s = getScheme4(s1 , s2 , s3 , s4);
        if(s != "") {
            scheme[i] = s;
            continue;
        }
        chk = 0;
        break;
        
    }
    //scout << scheme[1] << " ";
    if(chk == 1) {
        a = 1;
        sort(&scheme[1] , &scheme[n+1]);
        Fd(i , n-1 , 1) {
            if(scheme[i] != "aaaa" && scheme[i] != scheme[n]) {
                a = 0;
                break;
            }
        }
        if(a == 1) {
            cout << scheme[n];
        } else {
            cout << "NO";
        }
    } else {
        cout << "NO";
    }
    return 0;
}