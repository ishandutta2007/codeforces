#include <stdio.h>
#define N 20
char c[][N]={"","Washington","Adams","Jefferson","Madison","Monroe",
			"Adams","Jackson","Van Buren","Harrison","Tyler",
			"Polk","Taylor","Fillmore","Pierce","Buchanan",
			"Lincoln","Johnson","Grant","Hayes","Garfield",
			"Arthur","Cleveland","Harrison","Cleveland","McKinley",
			"Roosevelt","Taft","Wilson","Harding","Coolidge",
			"Hoover","Roosevelt","Truman","Eisenhower","Kennedy",
			"Johnson","Nixon","Ford","Carter","Reagan"};
int n;
int main(){
	scanf("%d",&n); puts(c[n]);
}