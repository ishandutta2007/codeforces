#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std; const int MEM_SZ = 30000; int mem[MEM_SZ]; void run(const string& s) { vector<size_t> bracket_stack; vector<size_t> opposite(s.length()); for (size_t i = 0; i < s.length(); ++i) { if (s[i] == '[') { bracket_stack.push_back(i); } else if (s[i] == ']') { opposite[i] = bracket_stack.back(); opposite[bracket_stack.back()] = i; bracket_stack.pop_back(); } } memset(mem, 0, sizeof(mem)); int* mem_ptr = mem; size_t instruction_ptr = 0; while (instruction_ptr < s.length()) { char c = s[instruction_ptr++]; if (c == ',') { *mem_ptr = getchar(); } else if (c == '.') { cout << *mem_ptr << " "; } else if (c == '<') { --mem_ptr; } else if (c == '>') { ++mem_ptr; } else if (c == '+') { ++*mem_ptr; } else if (c == '-') { --*mem_ptr; } else if (c == ']') { instruction_ptr = opposite[instruction_ptr - 1]; } else if (c == '[') { if (!*mem_ptr) { instruction_ptr = opposite[instruction_ptr - 1] + 1; } } } } int main() { ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	const string code = R"(
	+[
		->,
		----------[
			<+>
			--------------------------------------
			>>++++++++++
			[
				-<[->>+>+<<<]>>>[-<<<+>>>]<<
			]
			<[-]>
			>[-<<+>>]<
			<<
			[->+<]
		]
		<
	]
	>>[
		->
		,+++>
		,+++
		>>++++++++++
		[-<++++++++++[-<-<->>]>]
		<<<
		[->>>>>+>+<<<<<<]>>>>>>[-<<<<<<+>>>>>>]<<<<<<
		>
		[->>>>>+>+<<<<<<]>>>>>>[-<<<<<<+>>>>>>]<<<<<<
		>
		+++++++++++++++++++++++++
		<<
		[
			->>[-<+>>+<]>[-<+>]<<<
		]
		>>[-]
		>>>
		[
			->
			>+<
			[>-]>
			[>]<
			[
				<<<<<<+>>>>>++++++++++++++++++++++++++++++>-
			]<
			-<
		]
		>[-]<
		<<<<
		.
		,[-]<<
	]
	)";

	run(code);

	return 0;
}