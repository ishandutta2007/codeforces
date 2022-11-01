#include <bits/stdc++.h>

using namespace std;

int n;
char s[1010]; string str;

int main() {
    scanf("%d", &n);

    map<string, string> gs;
    gs["purple"] = "Power";
    gs["green"] = "Time";
    gs["blue"] = "Space";
    gs["orange"] = "Soul";
    gs["red"] = "Reality";
    gs["yellow"] = "Mind";

    for(int i = 0; i < n; i++) {
        scanf("%s", s); str = s;
        gs[str] = "";
    }

    int ans = 0;
    for(auto p : gs)
        if(p.second != "")
            ans++;

    printf("%d\n", ans);
    for(auto p : gs)
        if(p.second != "")
            printf("%s\n", p.second.c_str());
    return 0;
}