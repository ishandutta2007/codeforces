#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

double h, m, s, t1, t2;

int main() {
    scanf("%lf %lf %lf %lf %lf", &h, &m, &s, &t1, &t2);
    if(t1 > 11.9) t1 = 0;
    if(t2 > 11.9) t2 = 0;

    if(h > 11.9) h = 0;

    if(m > 0.5 || s > 0.5) h += 0.5;
    if(s > 0.5) m += 0.5;
    m /= 5.0;
    s /= 5.0;

    if(m > 11.9) m -= 12;
    if(s > 11.9) s -= 12;

    if(t1 < t2) swap(t1, t2);
    //printf("%f %f %f %f %f\n", t1, t2, h, m, s);

    int b1 = 0, b2 = 0;
    if(h > t1 || h < t2) b1++;
    if(s > t1 || s < t2) b1++;
    if(m > t1 || m < t2) b1++;

    if(h < t1 && h > t2) b2++;
    if(s < t1 && s > t2) b2++;
    if(m < t1 && m > t2) b2++;

    cerr << b1 << " " << b2 << endl;
    if(b1 && b2) printf("NO\n");
    else printf("YES\n");
    return 0;
}