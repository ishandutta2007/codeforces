#!/usr/bin/ruby
include Math

n, pos, l, r = readline().split().map(&:to_i)
if l == 1 and r == n
	puts 0
elsif l == 1
	puts (pos-r).abs + 1
elsif r == n
	puts (pos-l).abs + 1
else
	puts [(pos-l).abs + (r-l) + 2, (pos-r).abs + (r-l) + 2].min
end