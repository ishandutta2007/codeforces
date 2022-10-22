#include <stdio.h>
#include <ctype.h>

int main() {
	int n, c;
	scanf("%d", &n);
	char s[n+1];
	int count = 0;
	while (isspace(c = getchar()))
		;
	do {
		if (c == 'A')
			count++;
		else 
			count--;
	} while (isalpha(c = getchar()));
	if (count > 0)
		printf("Anton\n");
	else if (count < 0)
		printf("Danik\n");
	else
		printf("Friendship\n");
	return 0;
}