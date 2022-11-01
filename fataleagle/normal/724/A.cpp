#include <bits/stdc++.h>

using namespace std;

vector<string> days={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main()
{
    string s, t;
    cin>>s>>t;
    int a=find(days.begin(), days.end(), s)-days.begin();
    int b=find(days.begin(), days.end(), t)-days.begin();
    if((a+28)%7==b || (a+30)%7==b || (a+31)%7==b)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}