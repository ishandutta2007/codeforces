#!/usr/bin/ruby
include Math

n, k = readline().split().map(&:to_i)

if k == 1 then
	puts n
else
	puts (1 << n.to_s(2).length) - 1
end